#pragma once

#include <string/string.hpp>

/// pulsar base class.
/// take a look at Godots object
class Object {

public:
	template<class T>
	static T* castTo(Object* p_object) {
		return dynamic_cast<T*>(p_object);
	}

	template<class T>
	static const T* castTo(const Object* p_object) {
		return dynamic_cast<const T*>(p_object);
	}

	virtual String asString();

	virtual ~Object() = default;

};
