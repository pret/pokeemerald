Follow the OS-specific instructions below.

# Linux

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

Make sure that there is an environment variable called DEVKITARM with the path of the directory before the "bin" directory containing "arm-none-eabi-as", "arm-none-eabi-cpp", "arm-none-eabi-ld" and "arm-none-eabi-objcopy".

Then get the compiler from https://github.com/pikalaxalt/agbcc/tree/new_layout_with_libs and run the following commands.

```bash
make
make install prefix=PATH_OF_POKEEMERALD_DIRECTORY
```

Then in the pokeemerald directory, build the tools.

```bash
./build_tools.sh
```

Finally, build the rom.

```bash
make
```

To invoke the devkitARM compiler (`$DEVKITARM/bin/arm-none-eabi-gcc`), run
```bash
make modern
```

# Windows

Install [**devkitARM**](http://devkitpro.org/wiki/Getting_Started/devkitARM).

In the MSYS environment provided with devkitARM, use pacman to install the required dependencies.  TODO: Compile the list of required packages.

Then, follow the instructions for compiling on Linux.

# Mac

Installing pokeemerald on a Mac requires macOS >= 10.12 (Sierra or higher).

Download a [devkitPRO pacman](https://github.com/devkitPro/pacman/releases/tag/v1.0.0)

Run the following commands in Terminal:


```bash
xcode-select --install

sudo dkp-pacman -S devkitARM 

export DEVKITPRO=/opt/devkitpro
echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
export DEVKITARM=$DEVKITPRO/devkitARM
echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc
echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile

git clone https://github.com/pret/pokeemerald
git clone https://github.com/pikalaxalt/agbcc -b new_layout_with_libs

cd agbcc/
make
make install prefix=../pokeemerald 

cd ../pokeemerald
./build_tools.sh
```

And build the ROM with `make`.

# Faster builds

After the first build, subsequent builds are faster. You can further speed up the build:

## Parallel build

This significantly speeds up the build on modern machines.

By default `make` only runs a single thread. You can tell `make` to run on multiple threads with `make -j`. See the manfile for usage (`man make`).

The optimal value for `-j` is the number of logical cores on your machine. You can run `nproc` to see the exact number.

```bash
$ nproc
8
```

If you have 8 cores, run: `make -j8`

`-j` on its own will spawn a new thread for each job. A clean build will have thousands of jobs, which will be slower than not using -j at all.

## Disable the dependency scanning

If you've only changed `.c` or `.s` files, you can turn off the dependency scanning temporarily. Changes to any other files will be ignored, and the build will either fail or not reflect those changes.

`make NODEP=1`

