rendering_sources = files([
    'shader.cpp'
])

rendering_inc = include_directories('.')
rendering_dependencies = [gl, glad, core]

if host_machine.system() == 'linux'
	if meson.version().version_compare('>=0.62.0')
		rendering_dependencies += dl
	else
		EXTRA_CPP_ARGS += '-ldl'
	endif
endif

renderinglib = library('rendering', rendering_sources, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, dependencies: rendering_dependencies)
rendering = declare_dependency(include_directories: rendering_inc, dependencies: rendering_dependencies, link_with: renderinglib)

ALL_DEPENDENCIES += rendering
#test('rendering_test', executable('rendering_test', 'rendering_test.cpp', cpp_args: EXTRA_CPP_ARGS, dependencies: rendering))