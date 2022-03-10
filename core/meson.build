CORE_DEPS = []
CORE_SOURCES = []
core_includes = include_directories('.')

subdir('math')
subdir('string')
subdir('error')

corelib = library('core', CORE_SOURCES, include_directories: INCDIRS, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], link_with: [], install: true)
core = declare_dependency(include_directories: [core_includes, INCDIRS], link_with: corelib)

DEPENDENCIES += corelib
test('core_test', executable('core_test', 'core_test.cpp', link_with: [corelib], include_directories: [INCDIRS], cpp_args: EXTRA_CPP_ARGS))