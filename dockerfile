# Use the official Debian image as the base image
FROM debian:latest

# Set environment variables for non-interactive installation
ENV DEBIAN_FRONTEND=noninteractive

# Install necessary packages
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
        build-essential \
        binutils-arm-none-eabi \
        git \
        libpng-dev \
        ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# Clone the pokeemerald repository
#RUN git clone https://github.com/pret/pokeemerald /pokeemerald

# Set the working directory
RUN git clone https://github.com/pret/agbcc

WORKDIR /agbcc

# Build agbcc and install it
WORKDIR /

WORKDIR /pokeemerald


# Command to build the ROM
#CMD ["cd", "pokeemerald"]
#CMD ["make"]
