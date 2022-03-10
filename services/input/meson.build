INPUT_SOURCES = files([
	'input.cpp'
])
input_inc = include_directories('.')

inputlib = library('input', INPUT_SOURCES, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: [sdl2, core])
input = declare_dependency(include_directories: input_inc, dependencies: [sdl2, core], link_with: inputlib)

ALL_DEPENDENCIES += input

#test('input_test', executable('input_test', 'input_test.cpp', include_directories: DOCTEST_INC, cpp_args: EXTRA_CPP_ARGS, dependencies: [input]))