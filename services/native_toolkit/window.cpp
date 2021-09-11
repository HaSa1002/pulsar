#include "window.hpp"

namespace pulsar::ntk {
	void Window::shoot() {
		OnStart.emit();
	}
}