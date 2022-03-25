VISION_EDITOR_SOURCES = [
    'main.cpp'
]



executable('vision-editor', VISION_EDITOR_SOURCES, include_directories: DOCTEST_INC, cpp_args: [EXTRA_CPP_ARGS, '-DDOCTEST_CONFIG_DISABLE'], install: true, install_dir: '', dependencies: [sdl2, window])