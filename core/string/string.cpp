#include "string.hpp"

String String::utf8() const {
	return String(*this);
}

String::String() noexcept {

}

String::String(const char* data) noexcept {
	this->data = std::string(data);
}

String::String(const String& str) noexcept {
	data = str.data;
}

String::String(String&& str) noexcept {
	data = std::move(str.data);
}

String::String(const std::string& str) noexcept {
	data = str;
}

const char* String::get_data() {
	return data.data();
}

String String::operator+(const String& str) noexcept {
	return String(this->data + data);
}

String itos(int i) {
	return String(std::to_string(i));
}