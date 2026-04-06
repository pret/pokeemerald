FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
ENV PATH="/usr/lib/ccache:${PATH}"

RUN apt-get update && apt-get install -y \
    build-essential \
    binutils-arm-none-eabi \
    gcc-arm-none-eabi \
    git \
    make \
    python3 \
    ccache \
    libpng-dev \
    && rm -rf /var/lib/apt/lists/*

ENV CCACHE_DIR=/ccache

WORKDIR /workspace

CMD ["bash"]