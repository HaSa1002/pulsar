window_sources = files([
    'tool_window.cpp'
])

window_inc = include_directories('.')

libpng = dependency('libpng')

window_dependencies = [input, rendering, libpng]

windowlib = library('window', window_sources, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: window_dependencies) # or sdl2, core, input
window = declare_dependency(include_directories: window_inc, dependencies: window_dependencies, link_with: windowlib)

ALL_DEPENDENCIES += window
#test('window_test', executable('window_test', 'window_test.cpp', cpp_args: EXTRA_CPP_ARGS, dependencies: window))