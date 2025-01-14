/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (c) 2017 Tuomas Tynkkynen
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include <linux/sizes.h>

/* Physical memory map */

#define CONFIG_SYS_SDRAM_BASE		0x80000000

#define CONFIG_SYS_INIT_SP_ADDR         (CONFIG_SYS_SDRAM_BASE + SZ_2M)
#define CONFIG_SYS_LOAD_ADDR		CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MALLOC_LEN		SZ_16M

#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_CLK		100000000
#define CONFIG_SYS_NS16550_REG_SIZE	-4
#define CONFIG_SYS_NS16550_MEM32
#define CONFIG_CONS_INDEX		1
#define CONFIG_SYS_NS16550_COM1		0x10000

#define BOOT_TARGET_DEVICES(func) \
	func(VIRTIO, virtio, 0)

#include <config_distro_bootcmd.h>

#define CONFIG_EXTRA_ENV_SETTINGS \
	"fdtfile=bhyve-arm.dts\0" \
	"fdt_addr_r=0x80000000\0" \
	"kernel_addr_r=0x80200000\0" \
	BOOTENV

#endif /* __CONFIG_H */
