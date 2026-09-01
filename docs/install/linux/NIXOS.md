# NixOS instructions
Run the following command to start an interactive shell with the necessary packages:
```bash
nix-shell -p pkgsCross.arm-embedded.stdenv.cc git pkg-config libpng
```
