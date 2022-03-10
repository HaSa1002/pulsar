#define SDL_MAIN_HANDLED

#include <iostream>
#include "services/window/tool_window.hpp"

int main(int argc, char** argv) {
	ToolWindowSDL window {"Vision Editor", 900, 600};
	window.run();
}