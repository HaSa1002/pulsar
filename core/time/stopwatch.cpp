
#include "stopwatch.hpp"

float Stopwatch::getElapsedTime() const {
	const std::chrono::duration<float> duration = (std::chrono::steady_clock::now() - start);
	return duration.count();
}

float Stopwatch::restart() {
	const auto now = std::chrono::steady_clock::now();
	const std::chrono::duration<float> duration = (now - start);
	start = now;
	return duration.count();
}
