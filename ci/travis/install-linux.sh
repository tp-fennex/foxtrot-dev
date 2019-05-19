#!/bin/bash

# Dependency install script
sudo apt update
sudo apt install -y protobuf-compiler \
                    libboost-all-dev \
                    libprotobuf-dev \
                    libprotoc-dev

# Build and install latest SFML
sudo apt install -y libfreetype6-dev \
                    libx11-dev \
                    libxrandr-dev \
                    libudev-dev \
                    libglu1-mesa-dev \
                    freeglut3-dev \
                    mesa-common-dev \
                    libflac-dev \
                    libogg-dev \
                    libvorbis-dev \
                    libvorbisenc2 \
                    libvorbisfile3 \
                    libopenal-dev \
                    libpthread-stubs0-dev
cd foxtrot/vendor/sfml
cmake .
make
sudo make install