#!/bin/bash

# Dependency install script
#sudo apt update
#sudo apt install -y protobuf-compiler \
#                    libboost-all-dev \
#                    libprotobuf-dev \
#                    libprotoc-dev
#
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
                    libpthread-stubs0-dev \
                    lib
cd foxtrot/vendor/sfml
cmake .
make
sudo make install
cd ../../..

sudo apt install -y autoconf \
                    automake \
                    libtool \
                    curl \
                    make \
                    unzip


wget https://dl.bintray.com/boostorg/release/1.70.0/source/boost_1_70_0.tar.gz
tar -xvf boost_1_70_0.tar.gz
cd boost_1_70_0/tools/build
chmod a+x bootstrap.sh
./bootstrap.sh
chmod a+x b2
sudo ./b2 install
cd ../../..

git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git submodule update --init --recursive
./autogen.sh
./configure
make
make check
sudo make install
sudo ldconfig
cd ..

cd foxtrot/include/foxtrot/Event/proto
chmod a+x generate.sh
./generate.sh
cd ../../../../..