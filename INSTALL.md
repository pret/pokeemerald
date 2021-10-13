# Prerequisites

| Linux | macOS | Windows 10
| - | - | -
| none | [Xcode Command Line Tools Package][xcode] | [Windows Terminal][terminal] and [Windows Subsystem for Linux (WSL)][wsl]

[xcode]: https://developer.apple.com/library/archive/technotes/tn2339/_index.html
[terminal]: https://docs.microsoft.com/windows/terminal/get-started
[wsl]: https://docs.microsoft.com/windows/wsl/install-win10

Independently from the specific OS, make sure that the `gcc`, `g++`, `make`, `git`, and `libpng-dev` packages or their equivalents are installed and accessible to the development tools that are used by the project (this means that, for example, on Windows, the packages have to be installed in the WSL environment). The package names and installation methods may vary with each OS.

Install the devkitARM toolchain of devkitPro as per [the instructions on their wiki](https://devkitpro.org/wiki/devkitPro_pacman). On Windows, follow the Linux instructions inside WSL as any steps about the Windows installer do not apply.

**Debian-based distro users:** This applies to Debian, Ubuntu, and similar distros, including in WSL. If necessary, install the `libarchive13`, `pkg-config`, and `gdebi-core` packages to be able to install devkitPro.

**Windows 10 users:** WSL 2 is available in the 1903 release (build 18362) and later, therefore existing WSL 1 and [prerelease WSL](https://docs.microsoft.com/windows/wsl/install-legacy) users are recommended to update. Right-click the Start button or press `Win`+`X`, choose Run, and run `ms-settings:about` to determine the Windows version. Also check Windows Update to make sure your installation is up-to-date.

**Windows 7 and 8.1 users:** pret is no longer focusing on support in pokeemerald for [old versions of Windows](https://support.microsoft.com/help/13853) so consider upgrading to a current release of Windows 10 or try a third-party guide like [this one](https://www.pokecommunity.com/showthread.php?t=425246) instead.


# Installation

To set up the repository:

	git clone https://github.com/pret/pokeemerald
	git clone https://github.com/pret/agbcc

	cd ./agbcc
	./build.sh
	./install.sh ../pokeemerald

	cd ../pokeemerald

To build **pokeemerald.gba** for the first time and confirm it matches the official ROM image:

	make compare

If an OK is returned, then the installation went smoothly.

**Windows users:** Consider adding exceptions for the `pokeemerald` and `agbcc` folders in Windows Security using [these instructions](https://support.microsoft.com/help/4028485). This prevents Microsoft Defender from scanning them which might improve performance while building.


# Start

To build **pokeemerald.gba** with your changes:

	make

**macOS users:** If the base tools are not found in new Terminal sessions after the first successful build, run `echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile` once to prevent the issue from occurring again. Verify that the `devkitarm-rules` package is installed as well; if not, install it by running `sudo dkp-pacman -S devkitarm-rules`.


# Building guidance


## Parallel builds

See [the GNU docs](https://www.gnu.org/software/make/manual/html_node/Parallel.html) and [this Stack Exchange thread](https://unix.stackexchange.com/questions/208568) for more information.

To speed up building, run:

	make -j$(nproc)

`nproc` is not available on macOS. The alternative is `sysctl -n hw.ncpu` ([relevant Stack Overflow thread](https://stackoverflow.com/questions/1715580)).


## Debug info

To build **pokeemerald.elf** with enhanced debug info:

	make DINFO=1


## devkitARM's C compiler

This project supports the `arm-none-eabi-gcc` compiler included with devkitARM r52. To build this target, simply run:

	make modern


## Other toolchains

To build using a toolchain other than devkitARM, override the `TOOLCHAIN` environment variable with the path to your toolchain, which must contain the subdirectory `bin`.

	make TOOLCHAIN="/path/to/toolchain/here"

The following is an example:

	make TOOLCHAIN="/usr/local/arm-none-eabi"

To compile the `modern` target with this toolchain, the subdirectories `lib`, `include`, and `arm-none-eabi` must also be present.


# Useful additional tools

* [porymap](https://github.com/huderlem/porymap) for viewing and editing maps
* [poryscript](https://github.com/huderlem/poryscript) for scripting ([VS Code extension](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript))
* [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) for viewing and editing tilemaps
