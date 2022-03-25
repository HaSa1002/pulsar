NTK_SOURCES = files([
	'window.cpp'
])
ntk_inc = include_directories('.')

ntklib = library('ntk', NTK_SOURCES, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: core)
ntk = declare_dependency(include_directories: ntk_inc, link_with: ntklib, dependencies: core)

ALL_DEPENDENCIES += ntk
#test('ntk_test', executable('ntk_test', 'ntk_test.cpp', cpp_args: EXTRA_CPP_ARGS, dependencies: ntk))