#include "shader.hpp"

#include <glad/glad.h>
#include <iostream>
#include "core/error/error_macros.hpp"

Shader::Shader(const String& vertexCode, const String& fragmentCode) {
	compile(vertexCode, fragmentCode);
}

long Shader::compileShader(const String& source, unsigned int type) {
	unsigned int shader = glCreateShader(type);
	const char* src = source.get_data();
	glShaderSource(shader, 1, &src, nullptr);
	glCompileShader(shader);
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char message[512];
		glGetShaderInfoLog(shader, 512, nullptr, message);
		std::cout << "Failed to compile shader (" << success << "): " << message << "\n";
		glDeleteShader(shader);
		return -1;
	}
	return shader;
}

void Shader::use() {
	glUseProgram(glProgramId);
}

void Shader::set(const String& name, int value) {
	glUniform1i(glGetUniformLocation(glProgramId, name.get_data()), value);
}

void Shader::set(const String& name, unsigned int value) {
	glUniform1ui(glGetUniformLocation(glProgramId, name.get_data()), value);
}

void Shader::set(const String& name, float value) {
	glUniform1f(glGetUniformLocation(glProgramId, name.get_data()), value);
}

void Shader::set(const String& name, bool value) {
	glUniform1i(glGetUniformLocation(glProgramId, name.get_data()), static_cast<int>(value));
}

bool Shader::isWorking() {
	return working;
}

bool Shader::compile(const String& vertexCode, const String& fragmentCode) {
	long vertex = compileShader(vertexCode, GL_VERTEX_SHADER);
	ERR_FAIL_COND_V_MSG(vertex == -1, false, "Failed to compile vertex shader.");
	long fragment = compileShader(fragmentCode, GL_FRAGMENT_SHADER);
	ERR_FAIL_COND_V_MSG(vertex == -1, false, "Failed to compile fragment shader.");

	glProgramId = glCreateProgram();
	glAttachShader(glProgramId, static_cast<unsigned int>(vertex));
	glAttachShader(glProgramId, static_cast<unsigned int>(fragment));
	glLinkProgram(glProgramId);

	int success = 0;
	glGetProgramiv(glProgramId, GL_LINK_STATUS, &success);
	if (!success) {
		char message[512];
		glGetProgramInfoLog(glProgramId, 512, nullptr, message);
		std::cout << "Failed to link shader program: " << message << "\n";
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
	working = success;
	return working;
}
