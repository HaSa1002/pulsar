
#include "tool_window.hpp"
#include <SDL.h>
#include <SDL_events.h>

ToolWindowSDL::ToolWindowSDL(const String &title, int width, int height) {
	input_provider.registerInputFilter(&input);
	initialise(title, width, height);
}


void ToolWindowSDL::initialise(const String &title, int width, int height) {
	SDL_SetMainReady();
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "Failed to initialise SDL\n";
		return;
	}

	SDL_Window* window = SDL_CreateWindow(title.get_data(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
										  width, height,
										  SDL_WINDOW_VULKAN|SDL_WINDOW_MAXIMIZED|SDL_WINDOW_RESIZABLE);

	if (window == nullptr) {
		std::cerr << "Failed to create window\n";
		return;
	}
}

void ToolWindowSDL::run() {
	while (running) {
		pollEvents();
	}
}

ToolWindowSDL::~ToolWindowSDL() {
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

}
