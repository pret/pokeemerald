Note: For further information beyond this very basic guide, please visit mdBook's [official documentation](https://rust-lang.github.io/mdBook/).

## Running documentation website locally (Ubuntu WSL1/WSL2)
### Previous Requirements:
- Option 1: Install via Rust toolchain
    - Install Rust toolchain if you don't have it via the `sudo apt install cargo` command.
    - Install mdBook via the `cargo install mdbook` command. Once finished, this message will pop up, with {USER} being your Ubuntu
        ```
        warning: be sure to add `/home/{USER}/.cargo/bin` to your PATH to be able to run the installed binaries
        ```
    - Add `/home/{USER}/.cargo/bin` to your PATH (with {USER} being the Ubuntu username.)
        - Run command `nano ~/.profile` to edit the file.
        - Add the following lines, ***replacing {USER} with your Linux username.***
            ```diff
            # set PATH so it includes user's private bin if it exists
            if [ -d "$HOME/bin" ] ; then
                PATH="$HOME/bin:$PATH"
            fi

            # set PATH so it includes user's private bin if it exists
            if [ -d "$HOME/.local/bin" ] ; then
                PATH="$HOME/.local/bin:$PATH"
            fi

            +# set PATH so it includes cargo bin if it exists
            +if [ -d "/home/{USER}/.cargo/bin" ] ; then
            +    PATH="/home/{USER}/.cargo/bin:$PATH"
            +fi
            ```
        - Run the `source ~/.profile` command to refresh the path in the current session.
- Option 2: Install downloaded binaries directly
    - TODO: Add documentation of this process.

### Running the website
- Navigate to the `docs` folder on the repository.
- Run `mdbook serve`. Once started, you may now open the website on your browser by going to `http://127.0.0.1:3000`.
- Every change done to the `docs` folder will be reflected with an automatic refresh.
- To stop the server and go back to the terminal, press `Ctrl + C`.

### Modifying the website
- The navigation menu on the left is handled by `docs/SUMMARY.md`. Every file added needs to be added somewhere here in order to become visible, otherwise you'll get a 404 error.
- Any Markdown files (.md extension) added to the `docs/` directory will automatically be read by mdBook.
- To add Markdown files that are not in the `docs/` directory, you may create an empty `.md` file and add the following ***without the "----"***:
    ```md
    {{ ----#include ../INSTALL.md}}`
    ```
    This will include the `INSTALL.md` Markdown file from the root directory.

Once you're set up, you can now check your changes before pushing them to your repo! :D

We hope that this will make it easier for users to contribute to the documentation :)
