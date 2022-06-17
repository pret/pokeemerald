#!/bin/bash

set -Eeuo pipefail

SCRIPT="$(basename $0)"
SUMMARY="$SCRIPT: A script to build GBA roms from pret projects using Docker."
USAGE="usage: $SCRIPT [project path]"
DESCRIPTION=$(cat <<EOF
To use this tool, ensure that Docker is installed and configured on your machine. See https://docs.docker.com/get-docker for details.

Either run this script from the root directory of a pret GBA decompilation repository, or pass in the path to the target repository as a parameter. The build outputs will be located in the root of that directory.

Examples:

  $ cd pokeemerald && $SCRIPT

  $ $SCRIPT /path/to/pokefirered
EOF
)


if [[ $# -ge 2 ]]; then
  fmt >&2 << EOF
Error: Too many arguments!

$USAGE
EOF
  exit 2
fi

if [[ $# -eq 1 ]] && [[ $1 =~ ^(--help|-h)$ ]]; then
  fmt << EOF
$SUMMARY

$USAGE

$DESCRIPTION
EOF
  exit 0
fi

SOURCE_DIR=$(realpath ${1:-$PWD})
PROJECT_DIR="/project"
AGBCC_DIR="/agbcc"

docker build -t pret-builder \
             - << EOF
FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    binutils-arm-none-eabi \
    build-essential \
    git \
    libpng-dev \
  && rm -rf /var/lib/apt/lists/*

RUN git clone https://github.com/pret/agbcc $AGBCC_DIR \
  && cd $AGBCC_DIR \
  && ./build.sh
EOF


docker run --rm \
           --mount type=bind,source=$SOURCE_DIR,destination=$PROJECT_DIR \
           pret-builder \
           bash -c " \
              cd $AGBCC_DIR \
              && ./install.sh $PROJECT_DIR \
              && cd $PROJECT_DIR \
              && make -j \
           "
