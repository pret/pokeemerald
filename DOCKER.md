# Docker

Build pokeemerald without installing the toolchain on your host machine.

## Prerequisites

- [Docker](https://docs.docker.com/get-docker/) with Compose v2

## Usage

```bash
# Build the ROM
make docker-build

# Open a shell inside the container
make docker-shell

# Clean build artifacts
make docker-clean
```

The output ROM is written to `pokeemerald_modern.gba` in the project root.

## How it works

The container is an Ubuntu 24.04 image with the ARM cross-compilation toolchain (`gcc-arm-none-eabi`, `binutils-arm-none-eabi`) and build dependencies pre-installed. Your project directory is volume-mounted into the container at `/workspace`, so source edits on the host are immediately reflected.

The build uses `MODERN=1`, which compiles with the system `arm-none-eabi-gcc` rather than the legacy `agbcc` compiler. A persistent Docker volume caches `ccache` data across builds to speed up recompilation.

On first run, Docker will build the image - subsequent runs reuse the cached image.
