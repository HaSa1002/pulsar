window_sources = files([
    'tool_window.cpp'
])

window_inc = include_directories('.')

windowlib = library('window', window_sources, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: [input, gl, glad]) # or sdl2, core, input
window = declare_dependency(include_directories: window_inc, dependencies: [input, gl, glad], link_with: windowlib)

ALL_DEPENDENCIES += window
#test('window_test', executable('window_test', 'window_test.cpp', cpp_args: EXTRA_CPP_ARGS, dependencies: window))