Use this compiler:
https://github.com/tttapa/docker-arm-cross-toolchain

Installed at: /home/beuss/opt/x-tools/armv6-rpi-linux-gnueabihf/bin

Debugging with https://marketplace.visualstudio.com/items?itemName=webfreak.debug

Need gcc-multilib for clangd to find proper headers.

Based on: https://github.com/ArduCAM/RaspberryPi/tree/master/SPI_Camera

Pin config (see spiBegin()):
- MOSI GPIO10 (19)
- MISO GPIO 9 (21)
- SCLK GPIO11 (23)
- CS GPIO 8 (24)
