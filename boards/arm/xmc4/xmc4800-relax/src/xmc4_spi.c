/****************************************************************************
 * boards/arm/xmc4/xmc4800-relax/src/xmc4_spi.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <debug.h>
#include <errno.h>
#include <stdbool.h>

#include <nuttx/spi/spi.h>

#include "xmc4800-relax.h"
#include "xmc4_gpio.h"
#include "xmc4_spi.h"

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: xmc4_spidev_initialize
 *
 * Description:
 *   Called to configure SPI chip select GPIO pins.
 *
 ****************************************************************************/

void weak_function xmc4_spidev_initialize(void)
{
  /* Configure SPI0 chip selects */

#ifdef CONFIG_XMC4_SPI0
#endif

  /* Configure SPI1 chip selects */

#ifdef CONFIG_XMC4_SPI1
#endif

  /* Configure SPI2 chip selects */

#if defined(CONFIG_XMC4_SPI2)
#endif

  /* Configure SPI3 chip selects */

#ifdef CONFIG_XMC4_SPI3
#endif

  /* Configure SPI4 chip selects */

#ifdef CONFIG_XMC4_SPI4
  xmc4_gpio_config(GPIO_CS);
#endif
}

/****************************************************************************
 * Name:  xmc4_spi[n]select, xmc4_spi[n]status, and xmc4_spi[n]cmddata
 *
 * Description:
 *   These external functions must be provided by board-specific logic.  They
 *   are implementations of the select, status, and cmddata methods of the
 *   SPI interface defined by struct spi_ops_s (see include/nuttx/spi/spi.h).
 *   All other methods including xmc4_spibus_initialize()) are provided by
 *   common xmc4 logic. To use this common SPI logic on your board:
 *
 *   1. Provide logic in xmc4_boardinitialize() to configure SPI chip select
 *      pins.
 *   2. Provide xmc4_spi[n]select() and xmc4_spi[n]status() functions
 *      in your board-specific logic.  These functions will perform chip
 *      selection and status operations using GPIOs in the way your board
 *      is configured.
 *   2. If CONFIG_SPI_CMDDATA is defined in the NuttX configuration, provide
 *      xmc4_spi[n]cmddata() functions in your board-specific logic.  These
 *      functions will perform cmd/data selection operations using GPIOs in
 *      the way your board is configured.
 *   3. Add a call to xmc4_spibus_initialize() in your low level application
 *      initialization logic
 *   4. The handle returned by xmc4_spibus_initialize() may then be used to
 *      bind the SPI driver to higher level logic (e.g., calling
 *      mmcsd_spislotinitialize(), for example, will bind the SPI driver to
 *      the SPI MMC/SD driver).
 *
 ****************************************************************************/

/****************************************************************************
 * Name: xmc4_spi[n]select
 *
 * Description:
 *   PIO chip select pins may be programmed by the board specific logic in
 *   one of two different ways.  First, the pins may be programmed as SPI
 *   peripherals.  In that case, the pins are completely controlled by the
 *   SPI driver.  This method still needs to be provided, but it may be only
 *   a stub.
 *
 *   An alternative way to program the PIO chip select pins is as a normal
 *   GPIO output.  In that case, the automatic control of the CS pins is
 *   bypassed and this function must provide control of the chip select.
 *   NOTE:  In this case, the GPIO output pin does *not* have to be the
 *   same as the NPCS pin normal associated with the chip select number.
 *
 * Input Parameters:
 *   devid - Identifies the (logical) device
 *   selected - TRUE:Select the device, FALSE:De-select the device
 *
 * Returned Values:
 *   None
 *
 ****************************************************************************/

#ifdef CONFIG_XMC4_SPI0
void xmc4_spi0select(struct spi_dev_s *dev, uint32_t devid,
                     bool selected)
{
  spiinfo("devid: %d CS: %s\n",
          (int)devid, selected ? "assert" : "de-assert");
}
#endif

#ifdef CONFIG_XMC4_SPI1
void xmc4_spi1select(struct spi_dev_s *dev, uint32_t devid,
                     bool selected)
{
  spiinfo("devid: %d CS: %s\n",
          (int)devid, selected ? "assert" : "de-assert");
}
#endif

#ifdef CONFIG_XMC4_SPI2
void xmc4_spi2select(struct spi_dev_s *dev, uint32_t devid,
                     bool selected)
{
  spiinfo("devid: %d CS: %s\n",
          (int)devid, selected ? "assert" : "de-assert");
}
#endif

#ifdef CONFIG_XMC4_SPI3
void xmc4_spi3select(struct spi_dev_s *dev, uint32_t devid,
                     bool selected)
{
  spiinfo("devid: %d CS: %s\n",
          (int)devid, selected ? "assert" : "de-assert");
}
#endif

#ifdef CONFIG_XMC4_SPI4
void xmc4_spi4select(struct spi_dev_s *dev, uint32_t devid,
                     bool selected)
{
  spiinfo("devid: %d CS: %s\n",
          (int)devid, selected ? "assert" : "de-assert");

  xmc4_gpio_write(GPIO_CS, !selected);
}
#endif

/****************************************************************************
 * Name: xmc4_spi[n]status
 *
 * Description:
 *   Return status information associated with the SPI device.
 *
 * Input Parameters:
 *   devid - Identifies the (logical) device
 *
 * Returned Values:
 *   Bit-encoded SPI status (see include/nuttx/spi/spi.h).
 *
 ****************************************************************************/

#ifdef CONFIG_XMC4_SPI0
uint8_t xmc4_spi0status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI1
uint8_t xmc4_spi1status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI2
uint8_t xmc4_spi2status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI3
uint8_t xmc4_spi3status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI4
uint8_t xmc4_spi4status(struct spi_dev_s *dev, uint32_t devid)
{
  return 0;
}
#endif

/****************************************************************************
 * Name: xmc4_spi[n]cmddata
 *
 * Description:
 *   Some SPI interfaces, particularly with LCDs, and an auxiliary 9th data
 *   input that determines where the other 8 data bits represent command or
 *   data.  These interfaces control that CMD/DATA GPIO output
 *
 * Input Parameters:
 *   devid - Identifies the (logical) device
 *   cmd - Determines where command or data should be selected.
 *
 * Returned Values:
 *   Bit-encoded SPI status (see include/nuttx/spi/spi.h).
 *
 ****************************************************************************/

#ifdef CONFIG_SPI_CMDDATA
#ifdef CONFIG_XMC4_SPI0
int xmc4_spi0cmddata(struct spi_dev_s *dev, uint32_t devid, bool cmd)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI1
int xmc4_spi1cmddata(struct spi_dev_s *dev, uint32_t devid, bool cmd)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI2
int xmc4_spi2cmddata(struct spi_dev_s *dev, uint32_t devid, bool cmd)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI3
int xmc4_spi3cmddata(struct spi_dev_s *dev, uint32_t devid, bool cmd)
{
  return 0;
}
#endif

#ifdef CONFIG_XMC4_SPI4
int xmc4_spi4cmddata(struct spi_dev_s *dev, uint32_t devid, bool cmd)
{
  return 0;
}
#endif
#endif /* CONFIG_SPI_CMDDATA */
