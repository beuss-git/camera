cmake_minimum_required(VERSION 3.16)


set(CMAKE_C_COMPILER "/home/beuss/opt/x-tools/armv6-rpi-linux-gnueabihf/bin/armv6-rpi-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER "/home/beuss/opt/x-tools/armv6-rpi-linux-gnueabihf/bin/armv6-rpi-linux-gnueabihf-g++")

set(COMPILER_FLAGS "-g -fPIE -pie -fdiagnostics-color=always")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILER_FLAGS}")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${COMPILER_FLAGS}")

#add_definitions("-mcpu=arm1176jzf-s -marm -march=armv6 -mfpu=vfp -mfloat-abi=hard")

project(camera)

#add_definitions("-mcpu=arm1176jzf-s -marm -march=armv6 -mfpu=vfp -mfloat-abi=hard")
#add_definitions("-march=armv6zk -marm -mcpu=arm1176jzf-s -mtune=arm1176jzf-s -mfpu=vfp")
#add_definitions("-mabi=aapcs-linux -march=armv6 -marm -mbe32 -mfpu=vfp -mfloat-abi=hard -mfp16-format=none -mpic-data-is-text-relative -mtp=soft -mstructure-size-boundary=8")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(camera
src/main.c
src/Arducam.c
src/bsp_spi.c
)
