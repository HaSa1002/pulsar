#define DOCTEST_CONFIG_IMPLEMENT
#define DOCTEST_CONFIG_TREAT_CHAR_STAR_AS_STRING
#include "doctest.h"

int main(int argc, char** argv) {
	std::cout << "This is my life \n";
	doctest::Context context;
	context.applyCommandLine(argc, argv);
	context.setOption("no-breaks", true); 
	return context.run();
}