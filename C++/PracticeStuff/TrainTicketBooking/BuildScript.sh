#!/bin/bash
#
## Set the build directory name
BUILD_DIR="build"
#
## Check if the build directory exists
if [ ! -d "$BUILD_DIR" ]; then
#  # Create the build directory
    mkdir "$BUILD_DIR"
      echo "Created directory: $BUILD_DIR"
      fi
#
#      # Navigate to the build directory
      cd "$BUILD_DIR"
#
#      # Run cmake to generate build files
      cmake ..
      if [ $? -ne 0 ]; then
        echo "CMake generation failed"
          exit 1
      fi
#
        echo "CMake generation succeeded"

# Build the project
 cmake --build .
 if [ $? -ne 0 ]; then
   echo "Build failed"
     exit 1
     fi
#
     echo "Build succeeded"
