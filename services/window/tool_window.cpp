
#include <glad/glad.h>
#include "tool_window.hpp"

#include "core/time/stopwatch.hpp"

#include <SDL.h>
#include <SDL_events.h>



ToolWindowSDL::ToolWindowSDL(const String &title, int width, int height) :width{width}, height{height} {
	input_provider.registerInputFilter(&input);
	initialise(title);
}

// TODO: split window init and render init
void ToolWindowSDL::initialise(const String &title) {
	// 1. SDL
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to initialise SDL\n";
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 2. Window
	window = SDL_CreateWindow(title.get_data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
										  width, height,
										  SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

	if (window == nullptr) {
		std::cerr << "Failed to create window\n";
		return;
	}
	// 3. OpenGL
	glContext = SDL_GL_CreateContext(window);
	if (glContext == nullptr) {
		std::cerr << "Failed to create OpenGL Context!\n";
		return;
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to initialize GLAD" << std::endl;
		return;
	}

	if (SDL_GL_SetSwapInterval(1) != 0) {
		std::cerr << "Failed to enable vsync";
	}
	glViewport(0,0, width, height);

	// 4. Shaders
	unsigned int vertexShader;
	unsigned int fragmentShader;
	compileShader(getDefaultVertexShader(), &vertexShader, GL_VERTEX_SHADER);
	compileShader(getDefaultFragmentShader(), &fragmentShader, GL_FRAGMENT_SHADER);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success = 0;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		char message[512];
		glGetProgramInfoLog(shaderProgram, 512, nullptr, message);
		std::cout << "Failed to link shader program: " << message << "\n";
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	// 5. Buffer setups
	float vertices[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left
	};
	unsigned int indices[] = {
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void ToolWindowSDL::run() {
	Ref<Stopwatch> deltaClock{new Stopwatch};
	Ref<Stopwatch> clock{new Stopwatch};
	while (running) {
		pollEvents();
		float delta = deltaClock->restart();
		update(delta);
		render(delta, clock->getElapsedTime());
	}
}

ToolWindowSDL::~ToolWindowSDL() {
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void ToolWindowSDL::pollEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (input_provider.canConsumeEvent(event)) {
			input_provider.consumeEvent(event);
			continue;
		}
		switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			case SDL_WINDOWEVENT:
				parseWindowEvent(event.window);
				break;
			default:
				break;
		}
	}
}

/// Parses sdl window event into window state
/// TODO: Implementation
void ToolWindowSDL::parseWindowEvent(const SDL_WindowEvent& event) {
	switch (event.event) {
		case SDL_WINDOWEVENT_SIZE_CHANGED:
		case SDL_WINDOWEVENT_RESIZED:
			width = event.data1;
			height = event.data2;
			glViewport(0, 0, width, height);
			std::cout << "New Size: " << width << "x" << height << "\n";
			break;
	}
}

/// Notify something
void ToolWindowSDL::update(float delta) {

}

/// Render screen
void ToolWindowSDL::render(float delta, float elapsedTime) {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	// Render frame
	glUseProgram(shaderProgram);
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

	// Swap buffer
	SDL_GL_SwapWindow(window);
}

bool ToolWindowSDL::compileShader(const String& source, unsigned int* shader, unsigned int type) {
	*shader = glCreateShader(type);
	const char* src = source.get_data();
	glShaderSource(*shader, 1, &src, nullptr);
	glCompileShader(*shader);
	int success;
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char message[512];
		glGetShaderInfoLog(*shader, 512, nullptr, message);
		std::cout << "Failed to compile shader (" << success << "): " << message << "\n";
		return false;
	}
	return true;
}

String ToolWindowSDL::getDefaultVertexShader() {
	return String(R"(#version 330 core
layout (location = 0) in vec3 aPos;

void main() {
	gl_Position = vec4(aPos, 1.0);
})");
}

String ToolWindowSDL::getDefaultFragmentShader() {
	return String(R"(#version 330 core
out vec4 FragColor;

uniform vec4 ourColor;

void main() {
	FragColor = ourColor;
})");
}
