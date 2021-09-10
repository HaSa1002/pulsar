NTK_SOURCES = files([
	'window.hpp'
])

ntk = library('ntk', NTK_SOURCES, include_directories: [INC_CORE, INC_TEST], link_with: [core, LIB_TEST], cpp_args: EXTRA_CPP_ARGS)
DEPENDENCIES += ntk
test('ntk_test', executable('ntk_test', 'ntk_test.cpp', link_with: [ntk, core, LIB_TEST], include_directories: [INC_CORE, INC_TEST], cpp_args: EXTRA_CPP_ARGS))