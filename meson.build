project(
	'pulsar', 
	'cpp',
	version: '0.1',
	license: 'MIT',
	default_options: [
	'c_std=11',
	'cpp_std=c++17'
	]
)

DEPENDENCIES = []
if meson.get_compiler('cpp').get_id() == 'msvc'
    EXTRA_CPP_ARGS = ['-std:c++17']
else
    EXTRA_CPP_ARGS = []
endif
INCDIRS = include_directories('.', 'thirdparty/doctest')

subdir('thirdparty')

subdir('core')
subdir('services')
subdir('main')