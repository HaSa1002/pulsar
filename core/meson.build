CORE_DEPS = []
CORE_SOURCES = [
    'object.cpp',
    'reference.cpp',
]
core_includes = include_directories('.')

subdir('math')
subdir('string')
subdir('error')
subdir('time')

corelib = library('core', CORE_SOURCES, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true)
core = declare_dependency(include_directories: [core_includes, DOCTEST_INC], link_with: corelib)

ALL_DEPENDENCIES += core

core_test_sources = CORE_SOURCES
core_test_sources += 'core_test.cpp'
test('core_test', executable('core_test', core_test_sources, cpp_args: EXTRA_CPP_ARGS, include_directories: [DOCTEST_INC]))