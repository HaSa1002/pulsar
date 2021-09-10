#include "string.hpp"

String String::utf8() const {
	return String(*this);
}

String::String() {

}

String::String(const char* data) {
	this->data = std::string(data);
}

String::String(const String& str) {
	data = str.data;
}

String::String(String&& str) {
	data = std::move(str.data);
}

String::String(const std::string& str) {
	data = str;
}

const char* String::get_data() {
	return data.data();
}

String String::operator+(const String& str) {
	return String(this->data + data);
}

String itos(int i) {
	return String(std::to_string(i));
}