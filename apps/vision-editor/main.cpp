#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Starting\n";
    SDL_SetMainReady();
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Failed to initialise SDL\n";
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Vision editor", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          900, 600,
                                          SDL_WINDOW_VULKAN|SDL_WINDOW_MAXIMIZED|SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cerr << "Failed to create window\n";
    }

    bool running = true;

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}