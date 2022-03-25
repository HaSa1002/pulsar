#pragma once

#include "core/reference.hpp"

#include <jpeglib.h>

#include <istream>
#include <csetjmp>

class Image {
public:
private:
	char* data = nullptr;
	unsigned int width = 0;
	unsigned int height = 0;
	unsigned char channels = 0;

	struct JpegErrorHack {
		jpeg_error_mgr errorMgr;
		jmp_buf jumpBuffer;
	};

public:
	int loadPngFromStream(std::istream& source);
	int loadJpegFromStream(std::istream& source);

	[[nodiscard]] char* getData() const;
	[[nodiscard]] unsigned int getWidth() const;
	[[nodiscard]] unsigned int getHeight() const;
	[[nodiscard]] unsigned char getChannels() const;

	~Image();

private:
	static void errorExit(j_common_ptr cinfo);
	static void outputMessage(j_common_ptr cinfo);
};


