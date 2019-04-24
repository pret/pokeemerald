## Prerequisites

**Linux:** none

**macOS:** [Xcode Command Line Tools package](https://developer.apple.com/library/archive/technotes/tn2339/_index.html#//apple_ref/doc/uid/DTS40014588-CH1-DOWNLOADING_COMMAND_LINE_TOOLS_IS_NOT_AVAILABLE_IN_XCODE_FOR_MACOS_10_9__HOW_CAN_I_INSTALL_THEM_ON_MY_MACHINE_)

**Windows 10 (1709+):** [Windows Subsystem for Linux](https://docs.microsoft.com/windows/wsl/install-win10)

**Windows Vista, 7, 8, 8.1, and 10 (1507, 1511, 1607, 1703):** Choose one of the following two options.

* Get [Cygwin](https://cygwin.com/install.html) and [include](https://cygwin.com/cygwin-ug-net/setup-net.html#setup-packages) the `make`, `git`, `gcc-core`, `gcc-g++`, and `libpng-devel` packages.
* Get [MSYS2](https://www.msys2.org/) and the [pokeruby-tools](https://github.com/pret/pokeruby-tools).

If you are on Windows 10 1607 or 1703 and use [the prerelease version of the Linux subsystem](https://docs.microsoft.com/windows/wsl/install-legacy), consider uninstalling it.

----

Install the **devkitARM** toolchain of [devkitPro](https://devkitpro.org/wiki/Getting_Started) and, except for MSYS2, add its environment variables. To set up devkitPro in MSYS2, use the [graphical installer](https://github.com/devkitPro/installer/releases).

	export DEVKITPRO=/opt/devkitpro
	echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
	export DEVKITARM=$DEVKITPRO/devkitARM
	echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc


## Installation

To set up the repository:

	git clone https://github.com/pret/pokeemerald
	git clone https://github.com/pret/agbcc

	cd ./agbcc
	./build.sh
	./install.sh ../pokeemerald

	cd ../pokeemerald
	./build_tools.sh

To build **pokeemerald.gba**:

	make -j$(nproc)

To confirm it matches the official ROM image while building, do this instead:

	make compare -j$(nproc)

**Note:** If only `.c` or `.s` files were changed, turn off the dependency scanning temporarily. Changes to any other files will be ignored and the build will either fail or not reflect those changes.

	make -j$(nproc) NODEP=1

**Note 2:** If the build command is not recognized on Linux, including the Linux environment used within Windows, run `nproc` and replace `$(nproc)` with the returned value (e.g.: `make -j4`). Because `nproc` is not available on macOS, the alternative is `sysctl -n hw.ncpu`.
