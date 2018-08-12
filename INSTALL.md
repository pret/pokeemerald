Follow the OS-specific instructions below.

# Linux

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Make sure that there is an environment variable called DEVKITARM with the path of the directory before the "bin" directory containing "arm-none-eabi-as", "arm-none-eabi-cpp", "arm-none-eabi-ld" and "arm-none-eabi-objcopy".

Then get the compiler from https://github.com/pret/agbcc and run the following commands.

```
./build.sh
./install.sh PATH_OF_POKEEMERALD_DIRECTORY
```

Then in the pokeemerald directory, build the tools.

```
./build_tools.sh
```

Finally, build the rom.

```
make
```

# Windows

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Then get the compiled tools from https://github.com/pret/pokeruby-tools. Copy the `tools/` folder over the `tools/` folder in your pokeemerald directory.

You can then build pokeemerald using `make` in the MSYS environment provided with devkitARM.

# Mac

Installing pokeemerald on a Mac requires macOS >= 10.12 (Sierra or higher).

Download a [devkitPRO pacman](https://github.com/devkitPro/pacman/releases/tag/v1.0.0)

Run the following commands in Terminal:


```
xcode-select --install

sudo dkp-pacman -S devkitARM 

export DEVKITPRO=/opt/devkitpro
echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
export DEVKITARM=$DEVKITPRO/devkitARM
echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc
echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile

git clone https://github.com/pret/pokeemerald
git clone https://github.com/pret/agbcc

cd agbcc/
./build.sh
./install.sh ../pokeemerald 

cd ../pokeemerald
./build_tools.sh
```

And build the ROM with `make`.
