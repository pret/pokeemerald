# Instructions for ChromeOS

1. Enable the Linux terminal by following the instructions on [this page](https://chromeos.dev/en/productivity/terminal). Be sure to allocate enough space for the Linux install.
2. After the Linux terminal has finished installing, run the following command in the terminal to update and upgrade the Linux terminal:

    ```console
    sudo apt update && apt upgrade
    ```
3. Then install all dependencies by running the following command:

    ```console
    sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev python3
    ```
**NOTE**: The project must be kept in a directory inside the Linux filesystem, for example under `~/Decomps/pokeemerald-expansion`
