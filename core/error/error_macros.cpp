#include "error_macros.hpp"
#include <iostream>

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error) {
	_err_print_error(p_function, p_file, p_line, p_error, "");
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error) {
	_err_print_error(p_function, p_file, p_line, p_error.utf8().get_data(), "");
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const char *p_message) {
	const char *err_details;
	if (p_message && *p_message) {
		err_details = p_message;
	} else {
		err_details = p_error;
	}
	std::cerr << "Error: " << err_details << "\n\tat: " << p_function << "(" << p_file << ":" << p_line << ") - " << p_error << "\n";
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const char *p_message) {
	_err_print_error(p_function, p_file, p_line, p_error.utf8().get_data(), p_message);
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const String &p_message) {
	_err_print_error(p_function, p_file, p_line, p_error, p_message.utf8().get_data());
}

void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const String &p_message) {
	_err_print_error(p_function, p_file, p_line, p_error.utf8().get_data(), p_message.utf8().get_data());
}

void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const char *p_message, bool fatal) {
	String fstr(fatal ? "FATAL: " : "");
	String err(fstr + "Index " + p_index_str + " = " + itos(p_index) + " is out of bounds (" + p_size_str + " = " + itos(p_size) + ").");
	_err_print_error(p_function, p_file, p_line, err.utf8().get_data(), p_message);
}

void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const String &p_message, bool fatal) {
	_err_print_index_error(p_function, p_file, p_line, p_index, p_size, p_index_str, p_size_str, p_message.utf8().get_data(), fatal);
}