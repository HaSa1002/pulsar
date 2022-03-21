GLAD_SOURCES = files([
	'src/glad.cpp'
])
glad_inc = include_directories('include')
glad_deps = []
glad_args = []
if host_machine.system() == 'linux'
	if meson.version().version_compare('>=0.62.0')
		glad_deps += dependency('dl')
	else
		glad_args += '-ldl'
	endif
endif

gladlib = library('glad', GLAD_SOURCES, install: true, include_directories: glad_inc, link_args: glad_args, dependencies: glad_deps)
glad = declare_dependency(include_directories: glad_inc, link_with: gladlib, dependencies: glad_deps, link_args: glad_args)

ALL_DEPENDENCIES += glad