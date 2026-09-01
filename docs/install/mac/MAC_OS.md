# Instructions for macOS
1. If the Xcode Command Line Tools are not installed, download the tools [here](https://developer.apple.com/xcode/resources/), open your Terminal, and run the following command:

    ```bash
    xcode-select --install
    ```

2.  - If libpng is **not installed**, then go to [Installing libpng (macOS)](#installing-libpng-macos).
    - If pkg-config is **not installed**, then go to [Installing pkg-config (macos)](#installing-pkg-config-macos).
    - If devkitARM is **not installed**, then go to [Installing devkitARM (macOS)](#installing-devkitarm-macos).
    - Otherwise, **open the Terminal** and go to [Choosing where to store pokeemerald-expansion (macOS)](#choosing-where-to-store-pokeemerald-expansion-macos)

3. **Optional: To run tests**, if the homebrew environment is not installed, install the package manager using [this reference](https://brew.sh). Open your terminal and run the following commands:

    ```bash
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    brew install coreutils
    ```

4. **Optional: To run tests via Rosetta**
    - You probably don't want to do this as it's much slower. Most users can use native tools, but some may have other reasons to use this setup such as working with Intel-only custom tooling.
    - You will need an Intel-compatible homebrew installation. Understanding how to get one can be found [here](https://github.com/Homebrew/brew/issues/9173#issuecomment-729206868).
    - Install `coreutils` like in step 3, but using your Intel-compatible installation of homebrew.

### Installing libpng (macOS)
<details>
    <summary><i>Note for advanced users...</i></summary>

>   This guide installs libpng via Homebrew as it is the easiest method, however advanced users can install libpng through other means if they so desire.
</details>

1. Open the Terminal.
2. If Homebrew is not installed, then install [Homebrew](https://brew.sh/) by following the instructions on the website.
3. Run the following command to install libpng.

    ```bash
    brew install libpng
    ```
    libpng is now installed.

    Continue to [Installing pkg-config (macOS)](#installing-pkg-config-macos) if **pkg-config is not installed**. Otherwise, continue to [Installing devkitARM (macOS)](#installing-devkitarm-macos) if **devkitARM is not installed**.

    If both pkg-config and devkitARM are already installed, go to [Choosing where to store pokeemerald-expansion (macOS)](#choosing-where-to-store-pokeemerald-expansion-macos).

### Installing pkg-config (macOS)
<details>
    <summary><i>Note for advanced users...</i></summary>

>   This guide installs pkg-config via Homebrew as it is the easiest method, however advanced users can install pkg-config through other means if they so desire.
</details>

1. Open the Terminal.
2. If Homebrew is not installed, then install [Homebrew](https://brew.sh/) by following the instructions on the website.
3. Run the following command to install libpng.

    ```bash
    brew install pkg-config
    ```
    pkg-config is now installed.

    Continue to [Installing devkitARM (macOS)](#installing-devkitarm-macos) if **devkitARM is not installed**, otherwise, go to [Choosing where to store pokeemerald-expansion (macOS)](#choosing-where-to-store-pokeemerald-expansion-macos).

### Installing devkitARM (macOS)
1. Download the `devkitpro-pacman-installer.pkg` package from [here](https://github.com/devkitPro/pacman/releases).
2. Open the package to install devkitPro pacman.
3. In the Terminal, run the following commands to install devkitARM:

    ```bash
    sudo dkp-pacman -Sy
    sudo dkp-pacman -S gba-dev
    sudo dkp-pacman -S devkitarm-rules
    ```

    The command with gba-dev will ask for the selection of packages to install. Just press Enter to install all of them, followed by entering Y to proceed with the installation.

4. After the tools are installed, devkitARM must now be made accessible from anywhere by the system. To do so, run the following commands:

    ```bash
    export DEVKITPRO=/opt/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.zshrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.zshrc

    echo "if [ -f ~/.zshrc ]; then . ~/.zshrc; fi" >> ~/.zprofile
    ```
    *Note: Starting with macOS 10.15, the default Unix shell is now zsh. If you migrated from an older version of macOS, you might still be using bash. You can check my running `echo $0` in the terminal.*
    <details>
        <summary><i>If your terminal is using bash instead of zsh...</i></summary>

    ```bash
    export DEVKITPRO=/opt/devkitpro
    echo "export DEVKITPRO=$DEVKITPRO" >> ~/.bashrc
    export DEVKITARM=$DEVKITPRO/devkitARM
    echo "export DEVKITARM=$DEVKITARM" >> ~/.bashrc

    echo "if [ -f ~/.bashrc ]; then . ~/.bashrc; fi" >> ~/.bash_profile
    ```
    </details>

### Installing Python (macOS)
1. Download the latest Python package from [here](https://www.python.org/downloads/).
2. Open the package to install Python.

Python is now installed.

