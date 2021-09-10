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
INCDIRS = include_directories('.', 'thirdparty')

subdir('thirdparty')

subdir('core')
subdir('services')