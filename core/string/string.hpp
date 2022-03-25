#pragma once

//TODO: get rid of std::string

#include <string>

class String {
	std::string data;

public:
	[[nodiscard]] String utf8() const;
	[[nodiscard]] const char* get_data() const;

	String() noexcept;
	String(const char* data) noexcept;
	String(const std::string& str) noexcept;
	String(const String& str) noexcept;
	String(String&& str) noexcept;

	String operator+(const String& str) noexcept;
};

String itos(int i);