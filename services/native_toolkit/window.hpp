#include "common.hpp"
#include "doctest.h"
#include "server/event.hpp"
#include <Windows.h>

namespace pulsar::ntk {
	class Window {
	public:
		HRESULT ab;
		pulsar::Event<void> OnStart;
		void shoot() { OnStart.emit(); }
	};

	TEST_CASE("Window") {
		Window window;
	}
} // namespace pulsar::ntk