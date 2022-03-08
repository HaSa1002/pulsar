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

# At some point we need to fix our dependency management

DEPENDENCIES = []

EXTERNAL_DEPENDENCIES = []

if meson.get_compiler('cpp').get_id() == 'msvc'
    EXTRA_CPP_ARGS = ['-std:c++17']
else
    EXTRA_CPP_ARGS = []
endif

# LEAVE doctest here. It is required in a ton of things and this way our setup doesn't break
INCDIRS = include_directories('.', 'thirdparty/doctest')

# Thirdparty first (because everyone may uses them)
subdir('thirdparty')

# From low level to high leve

# Core next
subdir('core')

# Then services (required modules)
subdir('services')

# Then modules (optional)

# Main may be removed in the future as we are going to have many apps
subdir('main')