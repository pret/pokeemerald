# Instructions

These instructions explain how to set up the tools required to build **pokeemerald**, which assembles the source files into a ROM.

If you run into trouble, ask for help on Discord or IRC (see [README.md](README.md)).

## Windows
Windows has instructions for building with three possible terminals, if users encounter unexpected errors in following instructions for one of the terminals. These instructions are:
- [Windows 10 (WSL1)](#windows-10-wsl1) (**Fastest, highly recommended**, Windows 10 only)
- [Windows (msys2)](#windows-msys2) (Second fastest)
- [Windows (Cygwin)](#windows-cygwin) (Slowest)

Unscientific benchmarks suggest **msys2 is 2x slower** than WSL1, and **Cygwin is 5-6x slower** than WSL1.

> Note for advanced users: **WSL2** is an option and is even faster than **WSL1** if files are stored on the WSL2 file system, but some tools may have trouble interacting with the WSL2 file system over the network drive. For example, tools which use Qt versions before 5.15.2 such as [porymap](https://github.com/huderlem/porymap) may [have problems with parsing the `\\wsl$` network drive path](https://bugreports.qt.io/browse/QTBUG-86277).

All of the Windows instructions assume that the default drive is C:\\. If this differs to your actual drive letter, then replace C with the correct drive letter when reading the instructions.

**A note of caution**: As Windows 7 is officially unsupported by Microsoft and Windows 8 has very little usage, some maintainers are unwilling to maintain the Windows 7/8 instructions. Thus, these instructions may break in the future with fixes taking longer than fixes to the Windows 10 instructions.

## Windows 10 (WSL1)
WSL1 is the preferred terminal to build **pokeemerald**. The following instructions will explain how to install WSL1 (referred to interchangeably as WSL).
- If WSL (Debian or Ubuntu) is **not installed**, then go to [Installing WSL1](#Installing-WSL1).
- Otherwise, if WSL is installed, but it **hasn't previously been set up for another decompilation project**, then go to [Setting up WSL1](#Setting-up-WSL1).
- Otherwise, **open WSL** and go to [Choosing where to store pokeemerald (WSL1)](#Choosing-where-to-store-pokeemerald-WSL1).

### Installing WSL1
1. Open [Windows Powershell **as Administrator**](https://i.imgur.com/QKmVbP9.png), and run the following command (Right Click or Shift+Insert is paste in the Powershell).

    ```powershell
    dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
    ```

2. Once the process finishes, restart your machine.

3. The next step is to choose and install a Linux distribution from the Microsoft Store. The following instructions will assume Ubuntu as the Linux distribution of choice.

    > Note for advanced users: Advanced users can pick a preferred Linux distribution, but setup instructions may differ. Debian should work with the given instructions, but has not been tested. 

4. Open the [Microsoft Store Linux Selection](https://aka.ms/wslstore), click Ubuntu, then click Get, which will install the Ubuntu distribution.

    > Note 1: If a dialog pops up asking for you to sign into a Microsoft Account, then just close the dialog.  
    > Note 2: If the link does not work, then open the Microsoft Store manually, and search for the Ubuntu app (choose the one with no version number).  

### Setting up WSL1
Some tips before proceeding:
- In WSL, Copy and Paste is either done via
    - **right-click** (selection + right click to Copy, right click with no selection to Paste)
    - **Ctrl+Shift+C/Ctrl+Shift+V** (enabled by right-clicking the title bar, going to Properties, then checking the checkbox next to "Use Ctrl+Shift+C/V as Copy/Paste").
- Some of the commands that you'll run will ask for your WSL password and/or confirmation to perform the stated action. This is to be expected, just enter your WSL password and/or the yes action when necessary.

1. Open **Ubuntu** (e.g. using Search).
2. WSL/Ubuntu will set up its own installation when it runs for the first time. Once WSL/Ubuntu finishes installing, it will ask for a username and password (to be input in).

    > Note: When typing in the password, there will be no visible response, but the terminal will still read in input.

3. Update WSL/Ubuntu before continuing. Do this by running the following command:

    ```bash
    sudo apt update && sudo apt upgrade
    ```
    > Note: These commands will likely take a long time to finish.

> *Note: If the repository you plan to build was created before 2020/XX/YY (e.g. modifications of pokeemerald that haven't updated) then follow the [legacy WSL1 instructions](docs/legacy_WSL1_INSTALL.md). These repositories can be identified by the [older revision](https://github.com/pret/pokeemerald/blob/571c598/INSTALL.md) of the INSTALL.md*

4. Certain packages are required to build pokeemerald. Install these packages by running the following command:

    ```bash
    sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
    ```
    > Note: If the above command does not work, try the above command but replacing `apt` with `apt-get`.

### Choosing where to store pokeemerald (WSL1)
WSL has its own file system that's not natively accessible from Windows, but Windows files *are* accessible from WSL. So you're going to want to install pokeemerald within Windows. 

For example, say you want to store pokeemerald (and agbcc) in **C:\Users\\_\<user>_\Desktop\decomps**. If pokeemerald and/or agbcc hasn't been installed yet, then enter the following command, where *\<user>* is your **Windows** username:
```bash
cd /mnt/c/Users/<user>/Desktop/decomps
```
Note that the directory **must exist** in Windows. If you want to store pokeemerald in a dedicated folder that doesn't exist (e.g. the example provided above), then create the folder (e.g. using Windows Explorer) before executing the `cd` command.

> Note 1: The Windows C:\ drive is called /mnt/c/ in WSL.  
> Note 2: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "/mnt/c/users/<user>/Desktop/decomp folder"`.  
> Note 3: Windows path names are case-insensitive so adhering to capitalization isn't needed  
> Note 4: If pokeemerald is already installed, then run the following command instead (for the provided example path):
> ```bash
> cd /mnt/c/Users/<user>/Desktop/decomps/pokeemerald
> ```

If this works, then proceed to [Installation](#installation).

Otherwise, ask for help on Discord or IRC (see [README.md](README.md)), or continue reading below for [Windows instructions using msys2](#windows-msys2).

## Windows (msys2)

- If devkitPro is **not installed**, or is installed but without the GBA Development component, then go to [Installing devkitPro](#installing-devkitpro).
- If devkitPro is installed, but msys2 **hasn't previously been set up for another decompilation project**, then go to [Setting up msys2](#setting-up-msys2).
- Otherwise, **open msys2** and go to [Choosing where to store pokeemerald (msys2)](#choosing-where-to-store-pokeemerald-msys2).

### Installing devkitPro
1. Download the devkitPro installer [here](https://github.com/devkitPro/installer/releases).
2. Run the devkitPro installer. In the "Choose Components" screen, uncheck everything except GBA Development unless if you plan to use devkitPro for other purposes. Keep the install location as C:\devkitPro and leave the Start Menu option unchanged.

### Setting up msys2

Note that in msys2, Copy is Ctrl+Insert and Paste is Shift+Insert.

1. Open msys2 at C:\devkitPro\msys2\msys2_shell.bat.

2. Certain packages are required to build pokeemerald. Install these by running the following command:

    ```bash
    pacman -S make gcc zlib-devel git
    ```
    > Note: This command will ask for confirmation, just enter the yes action when prompted.

3. Download [libpng](https://sourceforge.net/projects/libpng/files/libpng16/1.6.37/libpng-1.6.37.tar.xz/download).

4. Change directory to where libpng was downloaded. By default, msys2 will start in the current user's profile folder, located at **C:\Users\\_\<user>_**, where *\<user>* is your Windows username. In most cases, libpng should be saved within a subfolder of the profile folder. For example, if libpng was saved to **C:\Users\\_\<user>_\Downloads** (the Downloads location for most users), enter this command:

    ```bash
    cd Downloads
    ```

    > Note 1: While not shown, msys uses forward slashes `/` instead of backwards slashes `\` as the directory separator.  
    > Note 2: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "Downloads/My Downloads"`.  
    > Note 3: Windows path names are case-insensitive so adhering to capitalization isn’t needed.   
    > Note 4: If libpng was saved elsewhere, you will need to specify the full path to where libpng was downloaded, e.g. `cd c:/devkitpro/msys2` if it was saved there.

5. Run the following commands to uncompress and install libpng.

    ```bash
    tar xf libpng-1.6.37.tar.xz
    cd libpng-1.6.37
    ./configure --prefix=/usr
    make check
    make install
    ```

6. Then finally, run the following command to change back to the user profile folder.

    ```bash
    cd
    ```

### Choosing where to store pokeemerald (msys2)
At this point, you can choose a folder to store pokeemerald into. If you're okay with storing pokeemerald in the user profile folder, then proceed to [Installation](#installation). Otherwise, you'll need to account for where pokeemerald is stored when changing directory to the pokeemerald folder.

For example, say you want to store pokeemerald (and agbcc) in **C:\Users\\_\<user>_\Desktop\decomps**. If pokeemerald and/or agbcc hasn't been installed yet, then enter the following command to **change directory** to the desired folder:

```bash
cd Desktop/decomps
```

Note that the directory **must exist** in Windows. If you want to store pokeemerald in a dedicated folder that doesn't exist (e.g. the example provided above), then create the folder (e.g. using Windows Explorer) before executing the `cd` command.

> Note: If pokeemerald is already installed, then run the following command instead (for the provided example path):
> ```bash
> cd Desktop/decomps/pokeemerald
> ```

If this works, then proceed to [Installation](#installation).

Otherwise, ask for help on Discord or IRC (see [README.md](README.md)), or continue reading below for [Windows instructions using Cygwin](#windows-cygwin).

## Windows (Cygwin)
1. If devkitPro is **not installed**, or is installed but without the GBA Development component, then follow the instructions used to [install devkitPro](#installing-devkitpro) for the msys2 setup before continuing. *Remember to not continue following the msys2 instructions by mistake!*

2.
    - If Cygwin is **not installed**, or does not have all of the required packages installed, then go to [Installing Cygwin](#installing-cygwin).
    - If Cygwin is installed, but **is not configured to work with devkitPro**, then go to [Configuring devkitPro for Cygwin](#configuring-devkitpro-for-cygwin).
    - Otherwise, **open Cygwin** and go to [Choosing where to store pokeemerald (Cygwin)](#choosing-where-to-store-pokeemerald-cygwin)

### Installing Cygwin
1. Download [Cygwin](https://cygwin.com/install.html): setup-x86_64.exe for 64-bit Windows, setup-x86.exe for 32-bit.

2. Run the Cygwin setup. Within the Cygwin setup, leave the default settings until the "Choose A Download Site" screen.

3. At "Choose a Download Site", select any mirror within the Available Download Sites.

4. At "Select Packages", set the view to "Full" (top left) and search for the following packages:
    - `make`
    - `git`
    - `gcc-core`
    - `gcc-g++`
    - `libpng-devel`

    To quickly find these, use the search bar and type the name of each package. Ensure that the selected package name is the **exact** same as the one you're trying to download, e.g. `cmake` is **NOT** the same as `make`.

5. For each package, double click on the text that says "**Skip**" next to each package to select the most recent version to install. If the text says anything other than "**Skip**", (e.g. Keep or a version number), then the package is or will be installed and you don't need to do anything.

6. Once all required packages have been selected, finish the installation.

### Configuring devkitPro for Cygwin

Note that in Cygwin, Copy is Ctrl+Insert and Paste is Shift+Insert.

1. Open **Cygwin**.

2. Run the following commands to configure devkitPro to work with Cygwin.

    ```bash
    export DEVKITPRO=/cygdrive/c/devkitpro
    echo export DEVKITPRO=$DEVKITPRO >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo export DEVKITARM=$DEVKITARM >> ~/.bashrc
    ```

    > Note: Replace the drive letter c with the actual drive letter if it is not c.

### Choosing where to store pokeemerald (Cygwin)

Cygwin has its own file system that's within Windows, at **C:\cygwin64\home\\_\<user>_**. If you don't want to store pokeemerald there, you'll need to account for where pokeemerald is stored when **changing directory** to the pokeemerald folder.

For example, if you want to store pokeemerald (and agbcc) in **C:\Users\\_\<user>_\Desktop\decomps**, enter this command, where *\<user>* is your **Windows** username:
```bash
cd c:/Users/<user>/Desktop/decomps
```
Note that the directory **must exist** in Windows. If you want to store pokeemerald in a dedicated folder that doesn't exist (e.g. the example provided above), then create the folder (e.g. using Windows Explorer) before executing the `cd` command.

> Note 1: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "c:/users/<user>/Desktop/decomp folder"`.  
> Note 2: Windows path names are case-insensitive so adhering to capitalization isn't needed  
> Note 3: If pokeemerald is already installed, then run the following command instead (for the provided example path):
> ```bash
> cd c:/Users/<user>/Desktop/decomps/pokeemerald
> ```

If this works, then proceed to [Installation](#installation). Otherwise, ask for help on Discord or IRC (see [README.md](README.md)).

## macOS
1. If the Xcode Command Line Tools are not installed, download the tools [here](https://developer.apple.com/library/archive/technotes/tn2339/_index.html), open your Terminal, and run the following command:

    ```bash
    xcode-select --install
    ```

2. - If devkitPro is **not installed**, then go to [Installing devkitPro (macOS)](#installing-devkitpro-macos).
   - Otherwise, **open the Terminal** and go to [Choosing where to store pokeemerald (macOS)](#choosing-where-to-store-pokeemerald-macos)

### Installing devkitPro (macOS)
1. Download the `devkitpro-pacman-installer.pkg` package from [here](https://github.com/devkitPro/pacman/releases).
2. Open the package to install devkitPro pacman.
3. devkitPro must be configured with the tools required for GBA development. Run the following commands:

    ```bash
    sudo dkp-pacman -Sy
    sudo dkp-pacman -S gba-dev
    sudo dkp-pacman -S devkitarm-rules
    ```

    The command with gba-dev will ask for the selection of packages to install. Just press Enter to install all of them, followed by entering Y to proceed with the installation.

4. After the tools are installed, devkitPro must now be made accessible from anywhere by the system. To do so, run the following commands:

    ```bash
    export DEVKITPRO=$HOME/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc

    echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile
    ```

### Choosing where to store pokeemerald (macOS)
At this point, you can choose a folder to store pokeemerald into. If you're okay with storing pokeemerald in the user folder, then proceed to [Installation](#installation). Otherwise, you'll need to account for where pokeemerald is stored when changing directory to the pokeemerald folder.

For example, say you want to store pokeemerald (and agbcc) in **~/Desktop/decomps**. If pokeemerald and/or agbcc hasn't been installed yet, then enter the following command to **change directory** to the desired folder:
```bash
cd Desktop/decomps
```
Note that the directory **must exist** in the folder system. If you want to store pokeemerald in a dedicated folder that doesn't exist (e.g. the example provided above), then create the folder (e.g. using Finder) before executing the `cd` command.

> Note 1: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "Desktop/decomp folder"`  
> Note 2: If pokeemerald is already installed, then run the following command instead (for the provided example path:
> ```bash
> cd Desktop/decomps/pokeemerald
> ```

If this works, then proceed to [Installation](#installation). Otherwise, ask for help on Discord or IRC (see [README.md](README.md)).

## Linux
Open Terminal and enter the following commands, depending on which distro you're using.

### Debian/Ubuntu-based distributions
Run the following command to install the necessary packages:
```bash
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
```
Then proceed to [Choosing where to store pokeemerald (Linux)](#choosing-where-to-store-pokeemerald-linux).

### Other distributions
_(Specific instructions for other distributions would be greatly appreciated!)_

1. Try to find the required software in its repositories:
    - `gcc`
    - `g++`
    - `make`
    - `git`
    - `libpng-dev`

2. Follow the instructions [here](https://devkitpro.org/wiki/devkitPro_pacman) to install devkitPro's pacman installer. As a reminder, the goal is to configure an existing pacman installation to recognize devkitPro's repositories.
3. Once devkitPro pacman is configured, run the following commands:

    ```bash
    sudo pacman -Sy
    sudo pacman -S gba-dev
    ```

    The last command will ask for the selection of packages to install. Just press Enter to install all of them, followed by entering Y to proceed with the installation.

### Choosing where to store pokeemerald (Linux)
At this point, you can choose a folder to store pokeemerald (and agbcc) into. If so, you'll have to account for the modified folder path when changing directory to the pokeemerald folder.

If this works, then proceed to [Installation](#installation). Otherwise, ask for help on Discord or IRC (see [README.md](README.md)).

## Installation

**Windows users:** Consider adding an exception for the `pokeemerald` and/or `decomps` folder in Windows Security using [these instructions](https://support.microsoft.com/help/4028485). This prevents Microsoft Defender from scanning them which might improve performance while building.

1. If pokeemerald is not already downloaded (some users may prefer to download pokeemerald via a git client like GitHub Desktop), run:

    ```bash
    git clone https://github.com/luckytyphlosion/pokeemerald
    ```

    > Note for WSL1: If you get an error stating `fatal: could not set 'core.filemode' to 'false'`, then run the following commands:
    >```bash
    >cd
    >sudo umount /mnt/c
    >sudo mount -t drvfs C: /mnt/c -o metadata,noatime
    >cd <folder where pokeemerald is to be stored>
    >```
    > Where *\<folder where pokeemerald is to be stored>* is the path of the folder [where you chose to store pokeemerald](#Choosing-where-to-store-pokeemerald-WSL1). Then run the `git clone` command again.

2. Install agbcc into pokeemerald. The commands to run depend on certain conditions:
- If agbcc has **not been built before** in the folder where you chose to store pokeemerald, run the following commands to build and install it into pokeemerald:

    ```bash
    git clone https://github.com/luckytyphlosion/agbcc
    cd agbcc
    ./build.sh
    ./install.sh ../pokeemerald
    ```

- **Otherwise**, if agbcc has been built before (e.g. if the git clone above fails), but was **last built on a different terminal** than the one currently used (only relevant to Windows, e.g. switching from msys2 to WSL1), then run the following commands to build and install it into pokeemerald:

    ```bash
    cd agbcc
    git clean -fX
    ./build.sh
    ./install.sh ../pokeemerald
    ```

- **Otherwise**, run the following commands to install agbcc into pokeemerald:

    ```bash
    cd agbcc
    ./install.sh ../pokeemerald
    ```

    > Note: If building agbcc or pokeemerald results in an error, try deleting the agbcc folder and re-installing agbcc as if it has not been built before.

3. Once agbcc is installed, change directory back to the base directory where pokeemerald and agbcc are stored:

    ```bash
    cd ..
    ```

Now you're ready to [build **pokeemerald**](#build-pokeemerald)
## Build pokeemerald
If you aren't in the pokeemerald directory already, then **change directory** to the pokeemerald folder:
```bash
cd pokeemerald
```
To build **pokeemerald.gba** for the first time and confirm it matches the official ROM image (Note: to speed up builds, see [Parallel builds](#parallel-builds)):
```bash
make compare
```
If an OK is returned, then the installation went smoothly.
> Note for Windows: if you switched terminals since the last build (e.g. from msys2 to WSL1), you must run `make clean-tools` once before any subsequent `make` commands.

To build **pokeemerald.gba** with your changes:
```bash
make
```

# Building guidance

## Parallel builds

See [the GNU docs](https://www.gnu.org/software/make/manual/html_node/Parallel.html) and [this Stack Exchange thread](https://unix.stackexchange.com/questions/208568) for more information.

To speed up building, first get the value of `nproc` by running the following command:
```bash
nproc
```
Builds can then be sped up by running the following command:
```bash
make -j<output of nproc>
```
Replace `<output of nproc>` with the number that the `nproc` command returned.

`nproc` is not available on macOS. The alternative is `sysctl -n hw.ncpu` ([relevant Stack Overflow thread](https://stackoverflow.com/questions/1715580)).

## Debug info

To build **pokeemerald.elf** with enhanced debug info:
```bash
make DINFO=1
```

## devkitARM's C compiler

This project supports the `arm-none-eabi-gcc` compiler included with devkitARM. If devkitARM (a.k.a. gba-dev) has already been installed as part of the platform-specific instructions, simply run:
```bash
make modern
```
Otherwise, follow the instructions below to install devkitARM.
### Installing devkitARM on WSL1

1. `gdebi-core` must be installed beforehand in order to install devkitPro (which facilitates the installation of devkitARM). Install this with the following command:

    ```bash
    sudo apt install gdebi-core
    ```
    > Note: If the above command does not work, try the above command but replacing `apt` with `apt-get`.

2. Once `gdebi-core` is done installing, download the devkitPro software package [here](https://github.com/devkitPro/pacman/releases). The file to download is `devkitpro-pacman.amd64.deb`.
3. Change directory to where the package was downloaded. For example, if the package file was saved to **C:\Users\\_\<user>_\Downloads** (the Downloads location for most users), enter this command, where *\<user> is your **Windows** username:

    ```bash
    cd /mnt/c/Users/<user>/Downloads
    ```

4. Once the directory has been changed to the folder containing the devkitPro package, run the following commands to install devkitPro.

    ```bash
    sudo gdebi devkitpro-pacman.amd64.deb
    sudo dkp-pacman -Sy
    sudo dkp-pacman -S gba-dev
    ```
    The last command will ask for the selection of packages to install. Just press Enter to install all of them, followed by entering Y to proceed with the installation.

    > Note: `devkitpro-pacman.amd64.deb` is the expected filename of the devkitPro package downloaded (for the first command). If the downloaded package filename differs, then use that filename instead.

5. Run the following command to set devkitPro related environment variables (alternatively, close and re-open WSL):

    ```bash
    source /etc/profile.d/devkit-env.sh
    ```

devkitARM is now installed.

### Installing devkitARM on Debian/Ubuntu-based distributions
1. If `gdebi-core` is not installed, run the following command:

    ```bash
    sudo apt install gdebi-core
    ```
2. Download the devkitPro software package [here](https://github.com/devkitPro/pacman/releases). The file to download is `devkitpro-pacman.amd64.deb`.
3. Change directory to where the package was downloaded. Then, run the following commands to install devkitARM:

    ```bash
    sudo gdebi devkitpro-pacman.amd64.deb
    sudo dkp-pacman -Sy
    sudo dkp-pacman -S gba-dev
    ```
    The last command will ask for the selection of packages to install. Just press Enter to install all of them, followed by entering Y to proceed with the installation.

    > Note: `devkitpro-pacman.amd64.deb` is the expected filename of the devkitPro package downloaded (for the first command). If the downloaded package filename differs, then use that filename instead.

4. Run the following command to set devkitPro related environment variables (alternatively, close and re-open the Terminal):

    ```bash
    source /etc/profile.d/devkit-env.sh
    ```

devkitARM is now installed.

## Other toolchains

To build using a toolchain other than devkitARM, override the `TOOLCHAIN` environment variable with the path to your toolchain, which must contain the subdirectory `bin`.
```bash
make TOOLCHAIN="/path/to/toolchain/here"
```
The following is an example:
```bash
make TOOLCHAIN="/usr/local/arm-none-eabi"
```
To compile the `modern` target with this toolchain, the subdirectories `lib`, `include`, and `arm-none-eabi` must also be present.

# Useful additional tools

* [porymap](https://github.com/huderlem/porymap) for viewing and editing maps
* [poryscript](https://github.com/huderlem/poryscript) for scripting ([VS Code extension](https://marketplace.visualstudio.com/items?itemName=karathan.poryscript))
* [Tilemap Studio](https://github.com/Rangi42/tilemap-studio) for viewing and editing tilemaps
