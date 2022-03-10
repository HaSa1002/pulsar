#pragma once
#define SDL_MAIN_HANDLED

#include <SDL_video.h>
#include <SDL_events.h>
#include "core/string/string.hpp"

#include "services/input/input.hpp"

/// Tool windows take care of event handling and the main loop.
/// They are thought as application bootstrapper.
class ToolWindow {
public:
	ToolWindow() = delete;
	virtual ~ToolWindow() = delete;
	virtual void run() = delete;
};

/// Uses SDL as backend. Only done to force separation of common features and implementation details
class ToolWindowSDL {
public:
	Input input;

public:
	ToolWindowSDL(const String& title, int width, int height);
	~ToolWindowSDL();

	void run();

private:
	InputProviderSDL input_provider;
	SDL_Window* window;
	bool running = true;

private:
	void initialise(const String &title, int width, int height);
	void pollEvents();
	void parseWindowEvent(const SDL_WindowEvent& event);
};