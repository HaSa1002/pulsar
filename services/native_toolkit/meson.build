NTK_SOURCES = files([
	'window.cpp'
])
INC_NTK = include_directories('.')

ntk = library('ntk', NTK_SOURCES, include_directories: INCDIRS, link_with: [core], cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true)
DEPENDENCIES += ntk
test('ntk_test', executable('ntk_test', 'ntk_test.cpp', link_with: [core, ntk], include_directories: INCDIRS, cpp_args: EXTRA_CPP_ARGS))