#pragma once

#include "key_list.hpp"

struct InputEvent {
	enum Type {
		None,
		Key,
	};

	const Type type = Type::None;
};


struct InputEventKey : public InputEvent {
	bool pressed = false;
	bool repeated = false;
	Scancode::Scancode scancode;
	Keycode::Keycode keycode;
	Keymod::Keymod modifier;

	InputEventKey() { }

	const Type type = Key;
};