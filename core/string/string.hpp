#pragma once

//TODO: get rid of std::string

#include <string>

class String {
	std::string data;

	public:
	String utf8() const;
	const char* get_data();

	String();
	String(const char* data);
	String(const std::string& str);
	String(const String& str);
	String(String&& str);

	String operator+(const String& str);
};

String itos(int i);