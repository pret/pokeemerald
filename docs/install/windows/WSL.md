# Windows WSL instructions
## Choosing WSL version
If you must store your project on the Windows file system (under /mnt/c/), you should use WSL1.
If you want the best performance and least amount of issues with Windows interfering with compiling the project, use WSL2 and store the project on the Linux file system (under ~/).
## Installing WSL
1. Open [Windows Powershell **as Administrator**](https://i.imgur.com/QKmVbP9.png), and run the following commands (Right Click or Shift+Insert is paste in the Powershell).

    ```powershell
	wsl --install -d Ubuntu --enable-wsl1
    ```

2. Once the process finishes, restart your machine.

### WSL1
3. Open Windows Powershell **as Administrator** again (after restarting), and run the following command to configure Ubuntu to use WSL1.

    ```powershell
    wsl --set-version Ubuntu 1
    ```
### WSL2
3. Open Windows Powershell **as Administrator** again (after restarting), and run the following command to configure Ubuntu to use WSL2.

    ```powershell
    wsl --set-version Ubuntu 2
    ```

    <details>
        <summary><i>Note...</i></summary>

    >   WSL may open automatically after restarting, but you can ignore it for now.
    </details>

## Installing dependencies
Some tips before proceeding:
- In WSL, Copy and Paste is either done via
    - **right-click** (selection + right click to Copy, right click with no selection to Paste)
    - **Ctrl+Shift+C/Ctrl+Shift+V** (enabled by right-clicking the title bar, going to Properties, then checking the checkbox next to "Use Ctrl+Shift+C/V as Copy/Paste").
- Some of the commands that you'll run will ask for your WSL password and/or confirmation to perform the stated action. This is to be expected, just enter your WSL password and/or the yes action when necessary.

1. Open **Ubuntu** (e.g. using Search).
2. WSL/Ubuntu will set up its own installation when it runs for the first time. Once WSL/Ubuntu finishes installing, it will ask for a username and password (to be input in).
    <details>
        <summary><i>Note...</i></summary>

    >   When typing in the password, there will be no visible response, but the terminal will still read in input.
    </details>

3. Update WSL/Ubuntu before continuing. Do this by running the following command. These commands will likely take a long time to finish:

    ```bash
    sudo apt update && sudo apt upgrade
    ```

4. Certain packages are required to build pokeemerald Expansion. Install these packages by running the following command:

    ```bash
    sudo apt install build-essential binutils-arm-none-eabi gcc-arm-none-eabi libnewlib-arm-none-eabi git libpng-dev python3
    ```

## Choosing a location to store pokeemerald Expansion, WSL1
WSL has its own file system that's not natively accessible from Windows, but Windows files *are* accessible from WSL. So you're going to want to store pokeemerald Expansion within Windows.

For example, say you want to store pokeemerald Expansion in **C:\Users\\_\<user>_\Desktop\decomps**. First, ensure that the folder already exists. Then, enter this command to **change directory** to said folder, where *\<user>* is your **Windows** username:

```bash
cd /mnt/c/Users/<user>/Desktop/decomps
```

<details>
    <summary><i>Notes...</i></summary>

>   Note 1: The Windows C:\ drive is called /mnt/c/ in WSL.
>   Note 2: If the path has spaces, then the path must be wrapped with quotations, e.g. `cd "/mnt/c/users/<user>/Desktop/decomp folder"`.
>   Note 3: Windows path names are case-insensitive so adhering to capitalization isn't needed
</details>

## Choosing a location to store pokeemerald Expansion, WSL2
WSL has its own file system that's not natively accessible from Windows, but Windows files *are* accessible from WSL. But accessing files on the Windows file system with WSL2 is very slow, so you're going to want to store pokeemerald Expansion within WSL2.
To access the files on the WSL filesystem from Windowsm, you have to open the WSL filesystem as a network attached storage in the file explorer, it should be at the bottom of the left sidebar as "Ubuntu".

Thus you're going to make sure that you're in the WSL filesystem, then create the folder for decomps if it doesn't already exist, then move into that folder.

```bash
cd ~/
mkdir decomps
cd decomps
```
