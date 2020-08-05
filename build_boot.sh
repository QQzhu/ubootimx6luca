#!/bin/bash
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- mx6qluca_defconfig
make V=1 ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- -j4
