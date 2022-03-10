INPUT_SOURCES = files([
	'input.cpp'
])
INC_INPUT = include_directories('.')

input = library('input', INPUT_SOURCES, include_directories: INCDIRS, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: [sdl2, core])
DEPENDENCIES += input
test('input_test', executable('input', 'input_test.cpp', link_with: [input], include_directories: INCDIRS, cpp_args: EXTRA_CPP_ARGS, dependencies: [sdl2, core]))