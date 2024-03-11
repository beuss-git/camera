cmake_minimum_required(VERSION 3.16)

# Comment out these if compiling on the pi
set(CMAKE_C_COMPILER "/home/beuss/opt/x-tools/armv8-rpi3-linux-gnueabihf/bin/armv8-rpi3-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER "/home/beuss/opt/x-tools/armv8-rpi3-linux-gnueabihf/bin/armv8-rpi3-linux-gnueabihf-g++")

set(COMPILER_FLAGS "-g -fPIE -pie -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS}")

project(camera)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(camera
  src/main.c
  src/Arducam.c
  src/bsp_spi.c
)
