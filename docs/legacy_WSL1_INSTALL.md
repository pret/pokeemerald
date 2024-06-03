### Setting up WSL1 (Legacy Portion)

1. Certain packages are required to build pokeemerald. Install these packages by running the following command:

    ```bash
    sudo apt install build-essential git libpng-dev gdebi-core
    ```
    > Note: If the above command does not work, try the above command but replacing `apt` with `apt-get`.

2. Once the packages have finished installing, download the devkitPro pacman package [here](https://github.com/devkitPro/pacman/releases). The file to download is `devkitpro-pacman.amd64.deb`.

3. WSL has its own file system that's not accessible from Windows, but Windows files *are* accessible from WSL. To install the devkitPro package, you'll need to change to the **current working directory** where the package file was saved.

    For example, if the package file was saved to **C:\Users\\_\<user>_\Downloads** (the Downloads location for most users), enter this command, where *\<user>* is your **Windows** username:

    ```bash
    cd /mnt/c/Users/<user>/Downloads
    ```

    > Note 1: The Windows C:\ drive is called /mnt/c/ in WSL.
    > Note 2: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd     "/mnt/c/users/<user>/Downloads folder"`.
    > Note 3: Windows path names are case-insensitive so adhering to capitalization isn't needed

4. Once the directory has been changed to the folder containing the devkitPro pacman package, run the following commands to install devkitARM.

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

Proceed to [Choosing where to store pokeemerald (WSL1) of the current INSTALL.md](/INSTALL.md#choosing-where-to-store-pokeemerald-expansion-WSL1).
