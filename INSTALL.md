First, you must put a Pokémon Emerald (US) ROM in the root directory of the repository and name it `baserom.gba`. It should have a SHA1 checksum of `f3ae088181bf583e55daf962a92bb46f4f1d07b7`. Then, follow the OS-specific instructions below.

# Linux

* Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).
* get [**agbcc**](https://github.com/pret/agbcc)
  * build and install it.
    ```
    build.sh
    install.sh /path/to/pokeemerald
    ```
* in the `pokeemerald` dir run `./build_tools.sh`

# Windows

* Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

* Then get the compiled tools from https://github.com/pret/pokeruby-tools.
* Copy the "tools" folder over the "tools" folder in your pokeemerald directory.

# All
You can then build pokeemerald using "make"
