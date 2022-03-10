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

ALL_DEPENDENCIES = []

if meson.get_compiler('cpp').get_id() == 'msvc'
    EXTRA_CPP_ARGS = ['-std:c++17']
else
    EXTRA_CPP_ARGS = []
endif

# LEAVE doctest here. It is required in a ton of things and this way our setup doesn't break
DOCTEST_INC = include_directories('.', 'thirdparty/doctest')

# Thirdparty first (because everyone may uses them and they are self contained)
subdir('thirdparty')

# From low level to high level

# Core next
subdir('core')

# Then services (required modules)
subdir('services')

# Then modules (optional)
# We don't have any at the moment

# Main may be removed in the future as we are going to have many apps
# However, tests should be moved into a single executable in there
subdir('main')

# Build our apps
subdir('apps')