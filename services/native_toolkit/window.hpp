#pragma once

#include "core/common.hpp"
#include "core/server/event.hpp"
//#include "doctest.h"
//#include <Windows.h>

namespace pulsar::ntk {
	class Window {
	public:
		//HRESULT ab;
		pulsar::Event<void> OnStart;
		void shoot();
	};

	TEST_CASE("Window") {
		Window window;
	}
} // namespace pulsar::ntk