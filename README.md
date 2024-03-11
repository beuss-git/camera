Use this compiler if cross compiling (not in the raspberry pi itself):
https://github.com/tttapa/docker-arm-cross-toolchain
Instructions for installing it are in the repo^

If you are not cross-compiling you need to comment out the noted lines in *CMakeLists.txt* to remove the hardcoded compiler paths.

If you need to debug it, you can do so via this VSCode extension: https://marketplace.visualstudio.com/items?itemName=webfreak.debug
There is already a launch.json file in the .vscode folder so that should work with minimal modification.

Need gcc-multilib for clangd to find proper headers:
`sudo apt install gcc-multilib`

Based on: https://github.com/ArduCAM/RaspberryPi/tree/master/SPI_Camera

Pin config (see spiBegin()):
- MOSI GPIO10 (19)
- MISO GPIO 9 (21)
- SCLK GPIO11 (23)
- CS GPIO 8 (24)


### Compiling
```bash
cd camera
```
```bash
mkdir build && cd build
```
```bash
cmake .. && make -j
```

If you cross-compiled it locally you need to transfer it to the PI, you can use either scp or rsync for that (the same goes for the produced images).

If you didn't cross-compile it, you can now run it via `./camera`.

Refer to this for valid register/configuration values: https://www.arducam.com/downloads/datasheet/Arducam_MEGA_SPI_Camera_Application_Note.pdf 
