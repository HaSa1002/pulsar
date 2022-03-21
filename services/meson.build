subdir('native_toolkit')

sdl2 = dependency('sdl2')
gl = dependency('gl')

if host_machine.system() == 'linux'
	if meson.version().version_compare('>=0.62.0')
		dl = dependency('dl')
	else
		EXTRA_CPP_ARGS += '-ldl'
	endif
endif

subdir('input')
subdir('window')