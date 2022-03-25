#pragma once
#include "core/reference.hpp"

#include <chrono>

class Stopwatch : public RefCounted {
	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
public:
	[[nodiscard]] float getElapsedTime() const;
	float restart();
};


