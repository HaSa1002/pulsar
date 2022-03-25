#pragma once

#include "core/reference.hpp"
#include "core/string/string.hpp"

class Shader : public RefCounted {
	bool working = false;
public:
	unsigned int glProgramId = 0;

	Shader() = default;
	Shader(const String& vertexCode, const String& fragmentCode);
	bool compile(const String& vertexCode, const String& fragmentCode);

	bool isWorking();
	void use();

	void set(const String& name, float value);
	void set(const String& name, bool value);
	void set(const String& name, int value);
	void set(const String& name, unsigned int value);

private:
	long compileShader(const String& source, unsigned int type);
};


