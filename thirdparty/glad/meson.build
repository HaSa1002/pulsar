GLAD_SOURCES = files([
	'src/glad.cpp'
])
glad_inc = include_directories('include')

gladlib = library('glad', GLAD_SOURCES, install: true, include_directories: glad_inc)
glad = declare_dependency(include_directories: glad_inc, link_with: gladlib)

ALL_DEPENDENCIES += glad