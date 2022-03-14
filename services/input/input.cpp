#include "input.hpp"

#include <iostream>

#include <SDL_assert.h>
#include <SDL_events.h>
#include <SDL.h>


void InputProvider::registerInputFilter(Input* inputFilter) {
	input_filters.push_back(inputFilter);
}

void InputProvider::pushEvent(const InputEvent& event) {
	for (auto& filter: input_filters) {
		filter->pushEvent(event);
	}
}

bool InputProviderSDL::canConsumeEvent(SDL_Event& sdlEvent) {
	switch (sdlEvent.type) {
		case SDL_KEYDOWN:
		case SDL_KEYUP:
			// This should move down just above the default block.
			// But we need to implement the stuff first.
			return true;
		case SDL_CONTROLLERAXISMOTION:
		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
		case SDL_JOYAXISMOTION:
		case SDL_JOYBALLMOTION:
		case SDL_JOYHATMOTION:
		case SDL_JOYBUTTONDOWN:
		case SDL_JOYBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEWHEEL:
		default:
			return false;
	}
}

void InputProviderSDL::consumeEvent(SDL_Event& sdlEvent) {
	Ref<InputEvent> event = nullptr;
	switch (sdlEvent.type) {
		case SDL_KEYDOWN:
		case SDL_KEYUP: {
			SDL_KeyboardEvent& sdlKey = sdlEvent.key;
			Ref<InputEventKey> keyEvent{};
			keyEvent->keycode = static_cast<Keycode::Keycode>(sdlKey.keysym.sym);
			keyEvent->scancode = static_cast<Scancode::Scancode>(sdlKey.keysym.scancode);
			keyEvent->modifier = static_cast<Keymod::Keymod>(sdlKey.keysym.mod);
			keyEvent->pressed = sdlEvent.type == SDL_KEYDOWN;
			keyEvent->repeated = sdlKey.repeat != 0;
			event = keyEvent;
			break;
		}
		case SDL_CONTROLLERAXISMOTION:
		case SDL_CONTROLLERBUTTONDOWN:
		case SDL_CONTROLLERBUTTONUP:
		case SDL_JOYAXISMOTION:
		case SDL_JOYBALLMOTION:
		case SDL_JOYHATMOTION:
		case SDL_JOYBUTTONDOWN:
		case SDL_JOYBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEWHEEL:
		default:
			SDL_assert(false);
			break;
	}
}

void Input::pushEvent(const InputEvent& event) {

}
