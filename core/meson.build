CORE_DEPS = []
CORE_SOURCES = []
INC_CORE = include_directories('.')

subdir('math')
subdir('string')
subdir('error')

core = library('core', CORE_SOURCES, include_directories: [INCDIRS], cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], link_with: [], install: true)
DEPENDENCIES += core
test('core_test', executable('core_test', 'core_test.cpp', link_with: [core], include_directories: [INCDIRS], cpp_args: EXTRA_CPP_ARGS))