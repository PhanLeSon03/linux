/**
 * pcitest.h - PCI test uapi defines
 *
 * Copyright (C) 2016 Texas Instruments
 * Author: Kishon Vijay Abraham I <kishon@ti.com>
 *
 */

#ifndef __UAPI_LINUX_PCITEST_H
#define __UAPI_LINUX_PCITEST_H

#define PCITEST_BAR		_IO('P', 0x1)
#define PCITEST_LEGACY_IRQ	_IO('P', 0x2)
#define PCITEST_MSI		_IOW('P', 0x3, int)
#define PCITEST_WRITE		_IOW('P', 0x4, unsigned long)
#define PCITEST_READ		_IOW('P', 0x5, unsigned long)
#define PCITEST_COPY		_IOW('P', 0x6, unsigned long)

#endif /* __UAPI_LINUX_PCITEST_H */
