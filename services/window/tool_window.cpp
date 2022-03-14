
#include <glad/glad.h>
#include "tool_window.hpp"
#include <SDL.h>
#include <SDL_events.h>

ToolWindowSDL::ToolWindowSDL(const String &title, int width, int height) :width{width}, height{height} {
	input_provider.registerInputFilter(&input);
	initialise(title);
}


void ToolWindowSDL::initialise(const String &title) {
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to initialise SDL\n";
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	window = SDL_CreateWindow(title.get_data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
										  width, height,
										  SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);

	if (window == nullptr) {
		std::cerr << "Failed to create window\n";
		return;
	}
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
}

void ToolWindowSDL::run() {
	while (running) {
		pollEvents();
		update();
		render();
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
	switch (event.type) {
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
void ToolWindowSDL::update() {

}

/// Render screen
void ToolWindowSDL::render() {
	//glViewport(0, 0, width, height);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}
