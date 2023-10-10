/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _SENSOR_MT6701_H
#define _SENSOR_MT6701_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Initialize the MT6701 sensor.
 *
 * @param GPIO_SCLK GPIO pin for the SPI clock (SCLK)
 * @param GPIO_MISO GPIO pin for SPI data input (MISO)
 * @param GPIO_MOSI GPIO pin for SPI data output (MOSI)
 * @param GPIO_CS   GPIO pin for the SPI chip select (CS)
 */
void sensor_mt6701_init(int GPIO_SCLK, int GPIO_MISO, int GPIO_MOSI, int GPIO_CS);

/**
 * @brief Get the current shaft angle from the sensor hardware.
 *
 * @return The shaft angle in radians.
 */
float sensor_mt7601_getAngle();


#ifdef __cplusplus
}
#endif

#endif
