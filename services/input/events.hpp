#pragma once

#include "core/reference.hpp"
#include "key_list.hpp"

struct InputEvent : public RefCounted {
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