#!/bin/bash

# Define variables
swift_version="5.10"
swift_release="swift-$swift_version-RELEASE"
ubuntu_version="ubuntu22.04"
swift_url="https://download.swift.org/swift-5.10-release/ubuntu2204/swift-5.10-RELEASE/swift-5.10-RELEASE-ubuntu22.04.tar.gz"
swift_install_dir="$HOME/Swift"
swift_bin_path="$swift_install_dir/$swift_release-$ubuntu_version/usr/bin"

# Step 1: Install necessary dependencies
echo "Installing necessary dependencies..."
sudo apt-get update
sudo apt-get install -y clang-18 g++-14 libicu-dev libpython3-dev libtinfo6 libncurses6 libxml2 git cmake ninja-build pkg-config libcurl4-openssl-dev openssl libssl-dev uuid-dev libedit-dev

# Check if the installation was successful 
if [ $? -ne 0 ]; then
    echo "Failed to install dependencies."
    exit 1
fi

# Step 2: Create installation directory
echo "Creating installation directory..."
mkdir -p $swift_install_dir
cd $swift_install_dir

# Step 3: Download Swift
echo "Downloading Swift from $swift_url..."
wget $swift_url -O $swift_release.tar.gz

# Check if the download was successful
if [ $? -ne 0 ]; then
    echo "Failed to download Swift."
    exit 1
fi

# Step 4: Extract Swift
echo "Extracting Swift..."
tar -xzf $swift_release.tar.gz

# Check if the extraction was successful
if [ $? -ne 0 ]; then
    echo "Failed to extract Swift."
    exit 1
fi

# Step 5: Add Swift to PATH in .bashrc
echo "Adding Swift to PATH in .bashrc..."
echo "export PATH=$swift_bin_path:\$PATH" >> $HOME/.bashrc

# Source .bashrc to update current session
source $HOME/.bashrc

# Step 6: Cleanup downloaded tarball
rm $swift_release.tar.gz

# Step 7: Verify Swift installation
echo "Verifying Swift installation..."
swift --version

if [ $? -ne 0 ]; then
    echo "Swift installation failed."
    exit 1
else
    echo "Swift installation was successful."
fi
