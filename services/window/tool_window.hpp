#pragma once
#define SDL_MAIN_HANDLED

#include <SDL_video.h>
#include <SDL_events.h>
#include <SDL_render.h>
#include <SDL_opengl.h>
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
	static String getDefaultVertexShader();
	static String getDefaultFragmentShader();
	bool compileShader(const String& source, unsigned int* shader, unsigned int type);

	void run();

private:
	InputProviderSDL input_provider;
	SDL_Window* window;
	SDL_GLContext glContext;
	bool running = true;
	int width = 0;
	int height = 0;
	unsigned int vbo;
	unsigned int vao;
	unsigned int shaderProgram;

private:
	void initialise(const String &title);
	void pollEvents();
	void update();
	void render();
	void parseWindowEvent(const SDL_WindowEvent& event);
};