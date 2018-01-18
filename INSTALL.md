First, you must put a Pokémon Emerald (US) ROM in the root directory of the repository and name it `baserom.gba`. It should have a SHA1 checksum of `f3ae088181bf583e55daf962a92bb46f4f1d07b7`. Then, follow the OS-specific instructions below.

# Linux

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Make sure that there is an environment variable called DEVKITARM with the path of the directory before the "bin" directory containing "arm-none-eabi-as", "arm-none-eabi-cpp", "arm-none-eabi-ld" and "arm-none-eabi-objcopy".

Then get the compiler from https://github.com/pret/agbcc and run the following commands.

	build.sh
	install.sh PATH_OF_POKEEMERALD_DIRECTORY

Then in the pokeemerald directory, build the tools.

	build_tools.sh

Finally, build the rom.

	make

# Windows

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Then get the compiled tools from https://github.com/pret/pokeruby-tools. Copy the `tools/` folder over the `tools/` folder in your pokeemerald directory.

You can then build pokeemerald using `make` in the MSYS environment provided with devkitARM.
