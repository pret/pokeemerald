# Instructions

These instructions explain how to set up the tools required to build **pokeemerald**, which assembles the source files into a ROM.

If you run into trouble, ask for help on IRC or Discord (see [README.md](README.md)).

## Windows 10
WSL1 is the preferred terminal to build **pokeemerald**. The following instructions will explain how to install WSL1. These steps can be skipped if WSL1 is already installed.

### Installing WSL1
Open [Windows Powershell **as Administrator**](https://i.imgur.com/QKmVbP9.png), and run the following command (Shift+Insert is paste in the terminal).
```
dism.exe /online /enable-feature /featurename:Microsoft-Windows-Subsystem-Linux /all /norestart
```
Once the process finishes, restart your machine.

The next step is to choose and install a Linux distribution from the Microsoft Store. The following instructions will assume Ubuntu as the Linux distribution of choice. Advanced users can pick a preferred Linux distribution, but build instructions may differ.

Open the [Microsoft Store Linux Selection](https://aka.ms/wslstore), click Ubuntu, then click Get, which will install the Ubuntu distribution. If the link does not work, then open the Microsoft Store manually, and search for the Ubuntu app (choose the one with no version number).

### Setting up WSL1
Open **Ubuntu** (e.g. using Search). WSL/Ubuntu will set up its own installation when it runs for the first time. Once WSL/Ubuntu finishes installing, it will ask for a username and password (to be input in). Note that there will be no visible response when typing in the password, but the terminal will still read in input.

A few notes before proceeding
- In the terminal, Copy and Paste is either done via
    - **right-click** (selection + right click to Copy, right click with no selection to Paste)
    - **Ctrl+Shift+C/Ctrl+Shift+V** (enabled by right-clicking the title bar, going to Properties, then checking the checkbox next to "Use Ctrl+Shift+C/V as Copy/Paste").
- Some of the commands that you'll run will ask for your WSL password and/or confirmation to perform the stated action. This is to be expected, just enter your WSL password and/or the yes action when necessary.

Update WSL/Ubuntu before continuing. Do this by running the following command:
```bash
sudo apt update && sudo apt upgrade
```
Note that these commands will likely take a long time to finish.

Certain packages are required to build pokeemerald. Install these packages by running the following command:
```bash
sudo apt install build-essential binutils-arm-none-eabi git libpng-dev
```
(If the above command does not work, try the above command but replacing `apt` with `apt-get`).

WSL has its own file system that's not accessible from Windows, but Windows files *are* accessible from WSL. So you're going to want to install pokeemerald within Windows. You'll have to change the **current working directory** every time you open WSL.

For example, if you want to store pokeemerald (and agbcc) in **C:\Users\\_\<user>_\Desktop\decomps**, enter this command:
```bash
cd /mnt/c/Users/<user>/Desktop/decomps
```
Note that the directory **must exist** in Windows. If you want to store pokeemerald in a dedicated folder that doesn't exist (e.g. the example provided above), then create the folder (e.g. using Windows Explorer) before executing the `cd` command.
 
(The Windows C:\ drive is called /mnt/c/ in WSL. Replace <user> in the example path with your **Windows** username, and the drive letter with the letter of the drive where you want to save pokeemerald. Windows path names are case-insensitive so adhereing to capitalization isn't needed)

If this works, then proceed to [Installation](#Installation).

Otherwise, continue reading below for [the older Windows instructions](#windows).

## Windows
TODO: add general Windows instructions

## macOS
TODO: add macOS instructions

## Linux
TODO: add Linux instructions

## Installation
To download the pokeemerald repository:
```bash
git clone https://github.com/pret/pokeemerald
```
If agbcc isn't built, run the following commands to build and install it into pokeemerald:
```
git clone https://github.com/pret/agbcc
cd agbcc
./build.sh
./install.sh ../pokeemerald
```
Otherwise, run the following commands to install agbcc into pokeemerald:
```
cd agbcc
./install.sh ../pokeemerald
```
Then, change directory back to the base directory where pokeemerald and agbcc are stored:
```
cd ..
```
Now you're ready to [build **pokeemerald**](#build-pokeemerald)
## Build pokeemerald
First, change directory to the pokeemerald folder:
```bash
cd pokeemerald
```
To build **pokeemerald.gba** for the first time and confirm it matches the official ROM image:
```bash
make compare
```
If an OK is returned, then the installation went smoothly.

To build **pokeemerald.gba** with your changes:
```bash
make
```

**Windows users:** Consider adding an exception for the `pokeemerald` folder in Windows Security using [these instructions](https://support.microsoft.com/help/4028485). This prevents Microsoft Defender from scanning them which might improve performance while building.

**macOS users (this is probably outdated):** If the base tools are not found in new Terminal sessions after the first successful build, run `echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile` once to prevent the issue from occurring again. Verify that the `devkitarm-rules` package is installed as well; if not, install it by running `sudo dkp-pacman -S devkitarm-rules`.

# Building guidance

## Parallel builds

See [the GNU docs](https://www.gnu.org/software/make/manual/html_node/Parallel.html) and [this Stack Exchange thread](https://unix.stackexchange.com/questions/208568) for more information.

To speed up building, first get the value of `nproc`:
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

This project supports the `arm-none-eabi-gcc` compiler included with devkitARM. If devkitARM has already been installed as part of the platform-specific instructions, simply run:
```bash
make modern
```
Otherwise, follow the instructions below to install devkitARM.
### Installing devkitARM on WSL1

`gdebi-core` must be installed beforehand in order to install devkitPro (which facilitates the installation of devkitARM). Install this with the following command:
```bash
sudo apt install gdebi-core
```
(If the above command does not work, try the above command but replacing `apt` with `apt-get`).

Once `gdebi-core` is done installing, download the devkitPro software package [here](https://github.com/devkitPro/pacman/releases). The file to download is `devkitpro-pacman.amd64.deb`.

Change directory to where the package was downloaded. For example, if the package file was saved to **C:\Users\\_\<user>_\Downloads** (the Downloads location for most users), enter this command:
```bash
cd /mnt/c/Users/<user>/Downloads
```
(Replace <user> with your Windows username)

Once the directory has been changed to the folder containing the devkitPro package, run the following commands to install devkitPro.
```bash
sudo gdebi devkitpro-pacman.amd64.deb
sudo dkp-pacman -Sy
sudo dkp-pacman -S gba-dev
```
Note: the last command will ask for the selection of packages to install. Just press Enter to install all of them, followed by entering Y to proceed with the installation. `devkitpro-pacman.amd64.deb` is the expected filename of the devkitPro package downloaded (for the first command). If the downloaded package filename differs, then use that filename instead.

Run the following command to set devkitPro related environment variables (alternatively, close and re-open WSL):
```bash
source /etc/profile.d/devkit-env.sh
```
devkitARM is now installed.

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
