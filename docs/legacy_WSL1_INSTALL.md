### Setting up WSL1 (Legacy Portion)
Certain packages are required to build pokeemerald. Install these packages by running the following command:
```bash
sudo apt install build-essential git libpng-dev gdebi-core
```
(If the above command does not work, try the above command but replacing `apt` with `apt-get`).

Download the devkitPro software package [here](https://github.com/devkitPro/pacman/releases). The file to download is `devkitpro-pacman.amd64.deb`.

WSL has its own file system that's not accessible from Windows, but Windows files *are* accessible from WSL. To install the devkitPro package, you'll need to change to the **current working directory** where the package file was saved.

For example, if the package file was saved to **C:\Users\\_\<user>_\Downloads** (the Downloads location for most users), enter this command:

```bash
cd /mnt/c/Users/<user>/Downloads
```

(The Windows C:\ drive is called /mnt/c/ in WSL. Replace <user> in the example path with your **Windows** username. Windows path names are case-insensitive so adhereing to capitalization isn't needed)

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
Proceed to [Choosing where to store pokeemerald (WSL1) of the current INSTALL.md](/INSTALL.md#choosing-where-to-store-pokeemerald-WSL1).
