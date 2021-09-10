#include "core/common.hpp"
#include "services/native_toolkit/window.hpp"

int main(int argc, char** argv) {
	pulsar::ntk::Window win;
	win.OnStart += [] {
		std::cout << "Hello World\n";
	};
	win.shoot();
	return 0;
}