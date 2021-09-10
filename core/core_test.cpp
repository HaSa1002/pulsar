#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "server/event.hpp"

int main(int argc, char** argv) {
	printf("Just a test");
	doctest::Context context;
	context.applyCommandLine(argc, argv);
	context.setOption("no-breaks", true); 
	return context.run();
}