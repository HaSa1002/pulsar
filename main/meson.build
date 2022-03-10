MAIN_SOURCES = [
	'main.cpp'
]

executable('pulsar', MAIN_SOURCES, include_directories: DOCTEST_INC, dependencies: ALL_DEPENDENCIES, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, install_dir: '')
test('all_tests', executable('all_tests', 'main_test.cpp', include_directories: DOCTEST_INC, cpp_args: EXTRA_CPP_ARGS, dependencies: ALL_DEPENDENCIES))