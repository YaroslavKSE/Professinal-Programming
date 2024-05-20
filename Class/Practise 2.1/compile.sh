#!/bin/bash

# Check if at least one argument is provided
if [ "$#" -lt 1 ]; then
  echo "Usage: $0 source_file.cpp [-o output_binary]"
  exit 1
fi

# Set the source file and output binary
SOURCE_FILE=$1
OUTPUT_BINARY="a.out" # Default output binary name

# Check if output binary is provided
if [ "$#" -eq 3 ] && [ "$2" == "-o" ]; then
  OUTPUT_BINARY=$3
fi

# Ensure the bin directory exists
mkdir -p bin

# Compile the source file with the specified flags
clang++-18 -Wall -Wextra -Wpedantic -Werror -std=c++23 "$SOURCE_FILE" -o "bin/$OUTPUT_BINARY"
