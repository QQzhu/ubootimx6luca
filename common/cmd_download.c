#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <asm/arch-mx6/imx-regs.h>

static int do_mfgdownload(cmd_tbl_t *cmdtp, int flag, int argc, char *argv[]){
    u32 reg;
    printf("enter mfg download\n");
    
    reg = readl(SRC_BASE_ADDR + 0x40);
    reg |= 0x00000030;
    writel(reg, SRC_BASE_ADDR + 0x40);

    reg = readl(SRC_BASE_ADDR + 0x44);
    reg |= 0x10000000;
    writel(reg, SRC_BASE_ADDR + 0x44);

    do_reset(NULL, 0, 0, NULL);

    return 0;
}

U_BOOT_CMD(
    enmfg, 1, 1, do_mfgdownload,
    "mfg_mode - enter i.MX usb download mode",
    ""
);