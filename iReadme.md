### 1. Download base code
`git clone https://source.codeaurora.org/external/imx/uboot-imx -b nxp/imx_v2015.04_3.14.52_1.1.0_ga`

### 2. Basic modify
1. Create own board file
```
cp -rf board/freescale/mx6sabresd board/freescale/mx6qluca
```
2. Create board header file
```
cp include/configs/mx6sabresd.h include/configs/mx6qluca.h
```
3. Create default config file
```
cp configs/mx6qsabresd_defconfig configs/mx6qluca_defconfig
```
4. Modify mx6qluca_defconfig file
```
CONFIG_SYS_EXTRA_OPTIONS="IMX_CONFIG=board/freescale/mx6qluca/mx6qluca.cfg,MX6Q,SYS_USE_SPINOR"
CONFIG_ARM=y
CONFIG_TARGET_MX6QLUCA=y
CONFIG_DM=y
CONFIG_DM_THERMAL=y
```
5. Rename own board folder files
```
mv board/freescale/mx6qluca/mx6sabresd.c board/freescale/mx6qluca/mx6qluca.c
```
6. Create own board cfg(board/freescale/mx6qluca/mx6qluca.cfg))
```
cp board/freescale/mx6qluca/mx6q_4x_mt41j128.cfg board/freescale/mx6qluca/mx6qluca.cfg
```
```
/*
 * Copyright (C) 2011-2014 Freescale Semiconductor, Inc.
 * Jason Liu <r64343@freescale.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 *
 * Refer doc/README.imximage for more details about how-to configure
 * and create imximage boot image
 *
 * The syntax is taken as close as possible with the kwbimage
 */

#define __ASSEMBLY__
#include <config.h>
/* image version */
IMAGE_VERSION 2

/*
 * Boot Device : one of spi, sd, sata
 * the board has no nand and eimnor
 * spinor: flash_offset: 0x0400
 * sata:   flash_offset: 0x0400
 * sd/mmc: flash_offset: 0x0400
 */

/* the same flash_offset as sd */
BOOT_FROM      sd

#ifdef CONFIG_USE_PLUGIN
/*PLUGIN    plugin-binary-file    IRAM_FREE_START_ADDR*/
PLUGIN	board/freescale/mx6sabresd/plugin.bin 0x00907000
#else

#ifdef CONFIG_SECURE_BOOT
CSF CONFIG_CSF_SIZE
#endif

/*
 * Device Configuration Data (DCD)
 *
 * Each entry must have the format:
 * Addr-type           Address        Value
 *
 * where:
 *      Addr-type register length (1,2 or 4 bytes)
 *      Address   absolute address of the register
 *      value     value to be stored in the register
 */
DATA 4, 0x020e0798, 0x000C0000
DATA 4, 0x020e0758, 0x00000000
DATA 4, 0x020e0588, 0x00000030
DATA 4, 0x020e0594, 0x00000030
DATA 4, 0x020e056c, 0x00000030
DATA 4, 0x020e0578, 0x00000030
DATA 4, 0x020e074c, 0x00000030
DATA 4, 0x020e057c, 0x00000030
DATA 4, 0x020e058c, 0x00000000
DATA 4, 0x020e059c, 0x00000030
DATA 4, 0x020e05a0, 0x00000030
DATA 4, 0x020e078c, 0x00000030
DATA 4, 0x020e0750, 0x00020000
DATA 4, 0x020e05a8, 0x00000018
DATA 4, 0x020e05b0, 0x00000018
DATA 4, 0x020e0524, 0x00000018
DATA 4, 0x020e051c, 0x00000018
DATA 4, 0x020e0518, 0x00000018
DATA 4, 0x020e050c, 0x00000018
DATA 4, 0x020e05b8, 0x00000018
DATA 4, 0x020e05c0, 0x00000018
DATA 4, 0x020e0774, 0x00020000
DATA 4, 0x020e0784, 0x00000018
DATA 4, 0x020e0788, 0x00000018
DATA 4, 0x020e0794, 0x00000018
DATA 4, 0x020e079c, 0x00000018
DATA 4, 0x020e07a0, 0x00000018
DATA 4, 0x020e07a4, 0x00000018
DATA 4, 0x020e07a8, 0x00000018
DATA 4, 0x020e0748, 0x00000018
DATA 4, 0x020e05ac, 0x00000018
DATA 4, 0x020e05b4, 0x00000018
DATA 4, 0x020e0528, 0x00000018
DATA 4, 0x020e0520, 0x00000018
DATA 4, 0x020e0514, 0x00000018
DATA 4, 0x020e0510, 0x00000018
DATA 4, 0x020e05bc, 0x00000018
DATA 4, 0x020e05c4, 0x00000018
DATA 4, 0x021b0800, 0xa1390003
DATA 4, 0x021b080c, 0x001F001F
DATA 4, 0x021b0810, 0x001F001F
DATA 4, 0x021b480c, 0x001F001F
DATA 4, 0x021b4810, 0x001F001F
DATA 4, 0x021b083c, 0x43180330
DATA 4, 0x021b0840, 0x03180310
DATA 4, 0x021b483c, 0x43200330
DATA 4, 0x021b4840, 0x0320025C
DATA 4, 0x021b0848, 0x40363838
DATA 4, 0x021b4848, 0x38362E3C
DATA 4, 0x021b0850, 0x3E3C4840
DATA 4, 0x021b4850, 0x44364640
DATA 4, 0x021b081c, 0x33333333
DATA 4, 0x021b0820, 0x33333333
DATA 4, 0x021b0824, 0x33333333
DATA 4, 0x021b0828, 0x33333333
DATA 4, 0x021b481c, 0x33333333
DATA 4, 0x021b4820, 0x33333333
DATA 4, 0x021b4824, 0x33333333
DATA 4, 0x021b4828, 0x33333333
DATA 4, 0x021b08b8, 0x00000800
DATA 4, 0x021b48b8, 0x00000800
DATA 4, 0x021b0004, 0x00020036
DATA 4, 0x021b0008, 0x09444040
DATA 4, 0x021b000c, 0x8A8F7955
DATA 4, 0x021b0010, 0xFF328F64
DATA 4, 0x021b0014, 0x01FF00DB
DATA 4, 0x021b0018, 0x00001740
DATA 4, 0x021b001c, 0x00008000
DATA 4, 0x021b002c, 0x000026D2
DATA 4, 0x021b0030, 0x008F1023
DATA 4, 0x021b0040, 0x00000047
DATA 4, 0x021b0000, 0x841A0000
DATA 4, 0x021b001c, 0x04088032
DATA 4, 0x021b001c, 0x00008033
DATA 4, 0x021b001c, 0x00048031
DATA 4, 0x021b001c, 0x09408030
DATA 4, 0x021b001c, 0x04008040
DATA 4, 0x021b0020, 0x00005800
DATA 4, 0x021b0818, 0x00011117
DATA 4, 0x021b4818, 0x00011117
DATA 4, 0x021b0004, 0x00025576
DATA 4, 0x021b0404, 0x00011006
DATA 4, 0x021b001c, 0x00000000

/* set the default clock gate to save power */
DATA 4, 0x020c4068, 0x00C03F3F
DATA 4, 0x020c406c, 0x0030FC03
DATA 4, 0x020c4070, 0x0FFFC000
DATA 4, 0x020c4074, 0x3FF00000
DATA 4, 0x020c4078, 0x00FFF300
DATA 4, 0x020c407c, 0x0F0000C3
DATA 4, 0x020c4080, 0x000003FF

/* enable AXI cache for VDOA/VPU/IPU */
DATA 4, 0x020e0010, 0xF00000CF
/* set IPU AXI-id0 Qos=0xf(bypass) AXI-id1 Qos=0x7 */
DATA 4, 0x020e0018, 0x007F007F
DATA 4, 0x020e001c, 0x007F007F

/*
 * Setup CCM_CCOSR register as follows:
 *
 * cko1_en  = 1	   --> CKO1 enabled
 * cko1_div = 111  --> divide by 8
 * cko1_sel = 1011 --> ahb_clk_root
 *
 * This sets CKO1 at ahb_clk_root/8 = 132/8 = 16.5 MHz
 */
DATA 4, 0x020c4060, 0x000000fb
#endif
```
7. Modify own board Makefile(board/freescale/mx6qluca/Makefile)
```
obj-y  := mx6sabresd.o
```
To
```
obj-y  := mx6qluca.o
```
8. Modify board/freescale/mx6qluca/Kconfig
```
if TARGET_MX6QLUCA

config SYS_BOARD
	default "mx6qluca"

config SYS_VENDOR
	default "freescale"

config SYS_SOC
	default "mx6"

config SYS_CONFIG_NAME
	default "mx6qluca"

endif
```
9. Add below to arch/arm/Kconfig
```
config TARGET_MX6QLUCA
    bool "Support mx6qluca"
    select CPU_V7
    select SUPPORT_SPL
```
```
source "board/freescale/mx6qluca/Kconfig"
```
### 3. Network modify
1. Net init work flow
```
board_init_f>>board_init_r>>initr_net>>eth_initialize
```
In eth_initialize
```
miiphy_init(),phy_init(),phy_env_init(),board_eth_init()
```
2. Details of eth_initialize()
```
miiphy_init():初始化mii_devs链表，该列表中是一系列象征mac控制器，每个miid_dev表示一条mdio总线，可挂载多个phy设备。
phy_init():根据宏定义(例如CONFIG_PHY_REALTEK、CONFIG_PHY_ATHEROS等)初始化相应一个或多个系列网卡，其中就有我们项目中使用的realtek(RTL8211E)系列网卡以及sabresd公版所使用的aheros(AR8031)系列网卡。
phy_env_init():初始化关于phy的一些uboot环境变量，这里我们不需要关心。
board_eth_init():网卡的板级初始化。
```
3. Details of board_eth_init()
```
setup_iomux_enet()函数配置网卡的rgmii接口，一般不用动这部分代码。
setup_pcie()配置板子pcie总线,具体这里也不用管。
cpu_eth_init()函数会做些网卡的芯片级初始化。
```
4. How to modify
Modify include/configs/mx6sabre_common.h
```
#define CONFIG_PHY_ATHEROS
...
#define CONFIG_FEC_MXC_PHYADDR 1
```
To
```
/* #define CONFIG_PHY_ATHEROS */
#define CONFIG_PHY_REALTEK
...
#define CONFIG_FEC_MXC_PHYADDR 5     //硬件地址
```
