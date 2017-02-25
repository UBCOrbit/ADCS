/**
  ******************************************************************************
  * @file    lsm9ds0_spi.h
  * @author  jenny yu, adam fink
  * @version v1.0
  * @date    2017-02-18
  * @brief   header file for lsm9ds0_spi.c
  ******************************************************************************

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_FLASH_H
#define __SPI_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* LSM9DS0 IMU Register addresses */ 
// 16 bit data = requires 2 8 bit registers 
// For each pair, the value is expressed in 16-bit as two’s complement left justified
#define GYRO_X_L 	0x28 
#define GYRO_X_H 	0x29
#define GYRO_Y_L 	0x2A
#define GYRO_Y_H 	0x2B
#define GYRO_Z_L 	0x2C
#define GYRO_Z_H 	0x2D
#define MAG_X_L 	0x08 
#define MAG_X_H		0x09
#define MAG_Y_L		0x0A
#define MAG_Y_H		0x0B
#define MAG_Z_L		0x0C
#define MAG_Z_H		0x0D
#define ACCEL_X_L	0x28 
#define ACCEL_X_H 	0x29
#define ACCEL_Y_L	0x2A
#define ACCEL_Y_H	0x2B
#define ACCEL_Z_L	0x2C
#define ACCEL_Z_H	0x2D 	




/* LSM9DS0 IMU Interface pins  */

OUT_X_L_G (28h), OUT_X_H_G (29h)
X-axis angular rate data.
OUT_Y_L_G (2Ah), OUT_Y_H_G (2Bh)
Y-axis angular rate data.
OUT_Z_L_G (2Ch), OUT_Z_H_G (2Dh)
Z-axis angular rate data.

OUT_X_L_M (08h), OUT_X_H_M (09h) 
X-axis magnetic data.
OUT_Y_L_M (0Ah), OUT_Y_H_M (0Bh)
Y-axis magnetic data.
OUT_Z_L_M (0Ch), OUT_Z_H_M (0Dh)
Z-axis magnetic data. 
OUT_X_L_A (28h), OUT_X_H_A (29h) 
X-axis acceleration data.
OUT_Y_L_A (2Ah), OUT_Y_H_A (2Bh)
Y-axis acceleration data.
OUT_Z_L_A (2Ch), OUT_Z_H_A (2Dh)
Z-axis acceleration data.
