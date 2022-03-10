window_sources = files([
    'tool_window.cpp'
])

INC_WINDOW = include_directories('.')

window = library('window', window_sources, include_directories: INCDIRS, link_with: [input], cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: [core, sdl2]) # or sdl2, core, input
DEPENDENCIES += window
#test('window_test', executable('window', 'input_test.cpp', link_with: [core, input, window], include_directories: INCDIRS, cpp_args: EXTRA_CPP_ARGS))