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

If the step `./build.sh` in the above list of commands fails with the error `Makefile:1: /opt/devkitpro/devkitARM/base_tools: No such file or directory`, then try installing the pacman package `devkitarm-rules` by executing the command

```
sudo dkp-pacman -S devkitarm-rules
```

Executing `./build.sh` again should now succeed.

# Faster builds

After the first build, subsequent builds are faster. You can further speed up the build:

## Parallel build

This significantly speeds up the build on modern machines.

By default `make` only runs a single thread. You can tell `make` to run on multiple threads with `make -j`. See the manfile for usage (`man make`).

The optimal value for `-j` is the number of logical cores on your machine. You can run `nproc` to see the exact number.

```
$ nproc
8
```

If you have 8 cores, run: `make -j8`

`-j` on its own will spawn a new thread for each job. A clean build will have thousands of jobs, which will be slower than not using -j at all.

## Disable the dependency scanning

If you've only changed `.c` or `.s` files, you can turn off the dependency scanning temporarily. Changes to any other files will be ignored, and the build will either fail or not reflect those changes.

`make NODEP=1`

