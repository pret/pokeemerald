# Prerequisites

| Linux | macOS | Windows 10 (build 18917+) | Windows 10 (1709+) | Windows Vista, 7, 8, 8.1, and 10 (1507, 1511, 1607, and 1703)
| ----- | ----- | ------------------------- | ------------------ | ---------------------------------------------------------
| none | [Xcode Command Line Tools package][xcode] | [Windows Subsystem for Linux 2][wsl2] | [Windows Subsystem for Linux][wsl] | MSYS2 (see below)

[xcode]: https://developer.apple.com/library/archive/technotes/tn2339/_index.html#//apple_ref/doc/uid/DTS40014588-CH1-DOWNLOADING_COMMAND_LINE_TOOLS_IS_NOT_AVAILABLE_IN_XCODE_FOR_MACOS_10_9__HOW_CAN_I_INSTALL_THEM_ON_MY_MACHINE_
[wsl2]: https://docs.microsoft.com/windows/wsl/wsl2-install
[wsl]: https://docs.microsoft.com/windows/wsl/install-win10

The [prerelease version of the Linux subsystem](https://docs.microsoft.com/windows/wsl/install-legacy) available in the 1607 and 1703 releases of Windows 10 is obsolete so consider uninstalling it.

Make sure that the `build-essential`, `git`, and `libpng-dev` packages are installed. The `build-essential` package includes the `make`, `gcc-core`, and `g++` packages so they do not have to be obtained separately. MSYS2 does not include `libpng-dev` so it must be built from source.

Install the **devkitARM** toolchain of [devkitPro](https://devkitpro.org/wiki/Getting_Started) and add its environment variables. For Windows versions without the Linux subsystem, the devkitPro [graphical installer](https://github.com/devkitPro/installer/releases) includes a preconfigured MSYS2 environment, thus the steps below are not required.

	export DEVKITPRO=/opt/devkitPro
	echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
	export DEVKITARM=$DEVKITPRO/devkitARM
	echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc


# Installation

To set up the repository:

	git clone https://github.com/pret/pokeemerald
	git clone https://github.com/pret/agbcc

	cd ./agbcc
	./build.sh
	./install.sh ../pokeemerald

	cd ../pokeemerald

To build **pokeemerald.gba** and confirm it matches the official ROM image:

	make compare

## Notes

* If the base tools are not found on macOS in new Terminal sessions after the first successful build, run `echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile` once to prevent the issue from occurring again. Verify that the `devkitarm-rules` package is installed as well; if not, install it by running `sudo dkp-pacman -S devkitarm-rules`.

* If the repository was previously set up using Cygwin, delete the `.exe` files in the subfolders of the `tools` folder except for `agbcc` and try building again. [Learn the differences between MSYS2 and Cygwin.](https://github.com/msys2/msys2/wiki/How-does-MSYS2-differ-from-Cygwin)

# Guidance

To build **pokeemerald.gba** with your changes:

	make

## Parallel builds

See [the GNU docs](https://www.gnu.org/software/make/manual/html_node/Parallel.html) and [this Stack Exchange thread](https://unix.stackexchange.com/questions/208568) for more information.

To speed up building, run:

	make -j$(nproc)

`nproc` is not available on macOS. The alternative is `sysctl -n hw.ncpu` ([relevant Stack Overflow thread](https://stackoverflow.com/questions/1715580)).

## Building without dependency scanning

If only `.c` or `.s` files were changed, turn off the dependency scanning temporarily. Changes to any other files will be ignored and the build will either fail or not reflect those changes.

	make NODEP=1

## Building with devkitARM's C compiler

This project supports the `arm-none-eabi-gcc` compiler included with devkitARM r52. To build this target, simply run:

	make modern

## Building with other toolchains

To build using a toolchain other than devkitARM, override the `TOOLCHAIN` environment variable with the path to your toolchain, which must contain the subdirectory `bin`.

	make TOOLCHAIN="/path/to/toolchain/here"

The following is an example:

	make TOOLCHAIN="/usr/local/arm-none-eabi"

To compile the `modern` target with this toolchain, the subdirectories `lib`, `include`, and `arm-none-eabi` must also be present.

## Building with debug info

To build **pokeemerald.elf** with enhanced debug info, use the `DINFO` variable.

	make DINFO=1
