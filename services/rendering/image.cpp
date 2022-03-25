#include "image.hpp"

#include "core/error/error_macros.hpp"
#include <png.h>
#include <jpeglib.h>

struct JpegStream {
	jpeg_source_mgr pub;
	std::istream* source;
	unsigned char buffer[4096];
};

void pngReadData(png_structp read, png_bytep data, png_size_t length) {
	std::istream* source = (std::istream*)png_get_io_ptr(read);
	source->read((char*)data, length);
}

// use libpng here
// https://www.piko3d.net/tutorials/libpng-tutorial-loading-png-files-from-streams
int Image::loadPngFromStream(std::istream& source) {
	delete[] data;
	data = nullptr;
	png_byte header[8];
	source.read((char*)header, 8);
	ERR_FAIL_COND_V_MSG(source.bad(), 1, "Failed to read PNG header!");
	int is_png = png_sig_cmp(header, 0, 8);
	ERR_FAIL_COND_V_MSG(is_png != 0, 2, "File is not a PNG image!");

	png_structp read = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
	ERR_FAIL_COND_V_MSG(read == nullptr, 3, "Failed to initialise read struct!");
	png_infop info = png_create_info_struct(read);
	if (info == nullptr) {
		png_destroy_read_struct(&read, &info, nullptr);
		ERR_FAIL_V_MSG(4, "Failed to initialise info struct!");
	}

	png_bytepp rows = nullptr;
	data = nullptr;

	if (setjmp(png_jmpbuf(read))) {
		png_destroy_read_struct(&read, &info, nullptr);
		delete[] rows;
		delete[] data;
		data = nullptr;

		ERR_FAIL_V_MSG(5, "An error occurred while parsing!");
	}

	png_set_read_fn(read, (void*)&source, pngReadData);
	png_set_sig_bytes(read, 8);
	png_read_info(read, info);

	png_uint_32 width = png_get_image_width(read, info);
	png_uint_32 height = png_get_image_height(read, info);
	png_uint_32 bitDepth = png_get_bit_depth(read, info);
	channels = png_get_channels(read, info);
	png_uint_32 colorType = png_get_color_type(read, info);

	switch (colorType) {
		case PNG_COLOR_TYPE_PALETTE:
			png_set_palette_to_rgb(read);
			channels = 3;
			break;
		case PNG_COLOR_TYPE_GRAY:
			if (bitDepth < 8) {
				png_set_expand_gray_1_2_4_to_8(read);
				bitDepth = 8;
				break;
			}
	}

	if (png_get_valid(read, info, PNG_INFO_tRNS)) {
		png_set_tRNS_to_alpha(read);
	}

	rows = new png_bytep[height];
	const unsigned int stride = width * bitDepth * channels / 8;
	data = new char[stride * height];

	for (size_t i = 0; i < height; ++i) {
		png_uint_32 q = (height - i - 1) * stride;
		rows[i] = (png_bytep)data + q;
	}

	png_read_image(read, rows);

	delete[] rows;
	png_destroy_read_struct(&read, &info, nullptr);

	return 0;
}


void init_source(j_decompress_ptr cinfo) {
	auto src = (JpegStream*)(cinfo->src);
	src->source->seekg(0);
}

boolean fill_buffer(j_decompress_ptr cinfo) {
	auto src = (JpegStream*)(cinfo->src);
	if (src->source->eof()) {
		src->buffer[0] = JPEG_EOI;
		src->pub.next_input_byte = src->buffer;
		src->pub.bytes_in_buffer = 1;
	}
	src->source->read((char*)src->buffer, 4096);
	src->pub.next_input_byte = src->buffer;
	src->pub.bytes_in_buffer = src->source->gcount();
	return true;
}

void skip(j_decompress_ptr cinfo, long bytes) {
	auto src = (JpegStream*)(cinfo->src);
	long in_buffer = static_cast<long>(src->pub.bytes_in_buffer);
	if (bytes < in_buffer) {
		src->pub.next_input_byte = &src->buffer[bytes];
		src->pub.bytes_in_buffer -= bytes;
	} else {
		bytes -= in_buffer;
		src->source->seekg(bytes , std::ios_base::cur);
		src->pub.next_input_byte = nullptr;
		src->pub.bytes_in_buffer = 0;
	}
}

void terminate_source(j_decompress_ptr cinfo) {}

void make_stream(j_decompress_ptr cinfo, std::istream* source) {
	JpegStream* src;
	/* The source object and input buffer are made permanent so that a series
    * of JPEG images can be read from the same file by calling jpeg_stdio_src
    * only before the first one. (If we discarded the buffer at the end of
    * one image, we'd likely lose the start of the next one.)
    * This makes it unsafe to use this manager and a different source
    * manager serially with the same JPEG object. Caveat programmer.
    */
	if (cinfo->src == nullptr)
	{
		/* first time for this JPEG object? */
		cinfo->src = (struct jpeg_source_mgr *)
				(*cinfo->mem->alloc_small) ((j_common_ptr) cinfo, JPOOL_PERMANENT, sizeof(JpegStream));
		src = reinterpret_cast<JpegStream*> (cinfo->src);
	}
	src = reinterpret_cast<JpegStream*> (cinfo->src);
	src->pub.init_source = init_source;
	src->pub.fill_input_buffer = fill_buffer;
	src->pub.skip_input_data = skip;
	src->pub.resync_to_restart = jpeg_resync_to_restart; /* use default method */
	src->pub.term_source = terminate_source;
	src->source = source;
	src->pub.bytes_in_buffer = 0; /* forces fill_input_buffer on first read */
	src->pub.next_input_byte = nullptr; /* until buffer loaded */
}


int Image::loadJpegFromStream(std::istream& source) {
	delete[] data;
	data = nullptr;

	jpeg_decompress_struct cinfo;
	JpegErrorHack errorHack;

	cinfo.err = jpeg_std_error(&errorHack.errorMgr);
	errorHack.errorMgr.error_exit = errorExit;
	errorHack.errorMgr.output_message = outputMessage;
	if (setjmp(errorHack.jumpBuffer)) {
		delete[] data;
		data = nullptr;
		jpeg_destroy_decompress(&cinfo);
		return 1;
	}

	jpeg_create_decompress(&cinfo);
	make_stream(&cinfo, &source);
	jpeg_read_header(&cinfo, true);
	cinfo.out_color_space = JCS_EXT_RGB;
	channels = 3;
	jpeg_start_decompress(&cinfo);
	width = cinfo.image_width;
	height = cinfo.image_height;
	unsigned int stride = width * cinfo.out_color_components;
	data = new char[height * stride];

	while (cinfo.output_scanline < height) {
		unsigned char* start = (unsigned char*)(data + cinfo.output_scanline * stride);
		jpeg_read_scanlines(&cinfo, &start, height - cinfo.output_scanline);
	}

	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	return 0;
}

void Image::errorExit(j_common_ptr cinfo) {
	// Very sneaky cast since err is first element in struct...
	JpegErrorHack* errorHack = (JpegErrorHack*) cinfo->err;
	(*cinfo->err->output_message)(cinfo);
	longjmp(errorHack->jumpBuffer, 1);
}

void Image::outputMessage(j_common_ptr cinfo) {
	char buffer[JMSG_LENGTH_MAX];
	(*cinfo->err->format_message)(cinfo, buffer);
	ERR_PRINT(buffer);
}


Image::~Image() {
	delete[] data;
}

char* Image::getData() const {
	return data;
}

unsigned int Image::getWidth() const {
	return width;
}

unsigned int Image::getHeight() const {
	return height;
}

unsigned char Image::getChannels() const {
	return channels;
}
