Use this compiler if cross compiling (not in the raspberry pi itself):
https://github.com/tttapa/docker-arm-cross-toolchain
Instructions for installing it are in the repo^

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
