CORE_DEPS = []
CORE_SOURCES = []
INC_CORE = include_directories('.')

subdir('math')
subdir('string')
subdir('error')

core = library('core', CORE_SOURCES, include_directories: INC_TEST, cpp_args: EXTRA_CPP_ARGS)
DEPENDENCIES += core
test('core_test', executable('core_test', 'core_test.cpp', link_with: core, include_directories: INC_TEST, cpp_args: EXTRA_CPP_ARGS))