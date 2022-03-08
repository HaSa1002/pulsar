# pulsar

pulsar is used to learn various game engine concepts and create a toolkit to be easily hackable, modular and to be tool friendly.

It used to be inspired by Godot's structure. However, it slowly transforms into its own.

**Current focus: Vision (GUI Framework and editor)**


## Installation

1. Install meson
2. Clone this repository
3. Install [dependencies](#dependencies)
4. Configure meson
   ```
   meson builddir && cd builddir
   meson compile
   meson test
   ```

## Dependencies

1. [sdl2](https://www.libsdl.org/)
2. more *will* follow :)

### Installing dependencies

Use the package manager of your distro.

If you are using Windows then [Scoop](https://scoop.sh/) is a neat way to get going.

!!! Warning
   
   The installation script of SDL is not working properly.
   Use the version in `misc\scoop\` instead

With build tools:

```commandline
scoop install meson ninja pkg-config misc\scoop\sdl2.json
```

Without build tools:

```commandline
scoop install misc\scoop\sdl2.json
```

## License

Licensed under the terms of "The Unlicense". See `LICENSE` for more information.
This software uses third party sources. Their licenses can be found in `thirdparty/README.md`.