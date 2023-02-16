# seed-phrase-checker

## Requirements

- M5Paper (Hardware)
- Visual Studio Code
- PlatformIO

Install driver from http://docs.m5stack.com/en/quick_start/m5paper/arduino

## Build and program

1. From the left menu, select PlatformIO.
2. Select `PROJECT TASK > m5stack-fire > General` > Upload to build firmware and upload to M5Paper


## Unit test

1. From the left menu, select PlatformIO.
2. Select `PROJECT TASK > native > Advanced > Test` to build firmware and upload to M5Paper


## Publish to M5Burner

1. Upload firmware from Visual Studio Code
2. Raunch M5Burner
3. Select Hamburger icon and Export Firmware
4. Set export parameters
   - COM: tty.wchusbserial***
   - BaudRate: 115200
   - Size: 4MB
   - File Path: any
5. Select `USER CUSTOM > Publish`


## Some parts of the source code come from external sources

- lib/hash/src: https://github.com/trezor/trezor-firmware/tree/master/crypto
