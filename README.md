# pulsar

pulsar is used to learn various game engine concepts and create a toolkit to be easily hackable, modular and to be tool friendly.

It used to be inspired by Godot's structure. However, it slowly transforms into its own.

**Current focus: Vision (GUI Framework and editor)**


## Installation

1. Clone this repository
2. Install [dependencies](#dependencies)
3. Configure meson
   ```
   meson builddir && cd builddir
   meson compile
   meson test
   ```

## Dependencies

Use the package manager of your distro. Use the distro-specific one liners below.
We maintain a list of the package names in `misc/<package manager>/dependencies`

1. [SDL (Simple Direct Media Layer)](https://www.libsdl.org/)
2. OpenGL >= 3.3
3. more *will* follow :)

### Windows

[Scoop](https://scoop.sh/) is a neat way to get going.

Scoop libraries can be found in `misc\scoop\dependencies`. However, just copy one of the two one liners below to get easily started.

The installation script of SDL is not working properly.
Use the version in `misc\scoop\` instead

With build tools:

```commandline
@("meson", "ninja", "pkg-config") + (Get-Content misc/scoop/dependencies) | ForEach-Object {scoop install $_}
```

Without build tools:

```commandline
Get-Content misc/scoop/dependencies | ForEach-Object {scoop install $_} 
```

### Debian (apt)

With build tools:

```commandline
pip3 install meson ninja | xargs -a misc/apt/dependencies sudo apt install
```

Without build tools:

```commandline
xargs -a misc/apt/dependencies sudo apt install
```

### macOS (brew)

With build tools:

```commandline
pip3 install meson ninja | brew install $(<misc/brew/dependencies)
```

Without build tools:

```commandline
brew install $(<misc/brew/dependencies)
```

## License

Licensed under the terms of "The Unlicense". See `LICENSE` for more information.
This software uses third party sources. Their licenses can be found in `thirdparty/README.md`.