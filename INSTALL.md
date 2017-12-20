First, you must put a Pokémon Emerald (US) ROM in the root directory of the repository and name it `baserom.gba`. It should have a SHA1 checksum of `f3ae088181bf583e55daf962a92bb46f4f1d07b7`. Then, follow the OS-specific instructions below.

# Linux

TBD

# Windows

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Then download [**pokeruby-tools**](https://github.com/pret/pokeruby-tools). Copy the `tools/` folder with the compiled `exe`s to the `tools/` folder in your `pokeemerald/` directory.

You can then build pokeemerald using `make` in the MSYS environment provided with devkitARM.
