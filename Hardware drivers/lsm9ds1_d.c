#include "lsm9ds1_reg.h"

/**
  * @defgroup    LSM9DS1
  * @brief       This file provides a set of functions needed to drive the
  *              lsm9ds1 enhanced inertial module.
  * @{
  *
  */

/**
  * @defgroup    LSM9DS1_Interfaces_Functions
  * @brief       This section provide a set of functions used to read and
  *              write a generic register of the device.
  *              MANDATORY: return 0 -> no Error.
  * @{
  *
  */

/**
  * @brief  Read generic device register
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  reg   register to read
  * @param  data  pointer to buffer that store the data read(ptr)
  * @param  len   number of consecutive register to read
  * @retval       interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t lsm9ds1_read_reg(lsm9ds1_ctx_t* ctx, uint8_t reg, uint8_t* data,
                         uint16_t len)
{
  int32_t ret;
  ret = ctx->read_reg(ctx->handle, reg, data, len);
  return ret;
}

/**
  * @brief  Write generic device register
  *
  * @param  ctx   read / write interface definitions(ptr)
  * @param  reg   register to write
  * @param  data  pointer to data to write in register reg(ptr)
  * @param  len   number of consecutive register to write
  * @retval       interface status (MANDATORY: return 0 -> no Error)
  *
  */
int32_t lsm9ds1_write_reg(lsm9ds1_ctx_t* ctx, uint8_t reg, uint8_t* data,
                          uint16_t len)
{
  int32_t ret;
  ret = ctx->write_reg(ctx->handle, reg, data, len);
  return ret;
}

/**
  * @defgroup    LSM9DS1_Sensitivity
  * @brief       These functions convert raw-data into engineering units.
  * @{
  *
  */

float_t lsm9ds1_from_fs2g_to_mg(int16_t lsb)
{
  return ((float_t)lsb *0.061f);
}

float_t lsm9ds1_from_fs4g_to_mg(int16_t lsb)
{
  return ((float_t)lsb *0.122f);
}

float_t lsm9ds1_from_fs8g_to_mg(int16_t lsb)
{
  return ((float_t)lsb *0.244f);
}

float_t lsm9ds1_from_fs16g_to_mg(int16_t lsb)
{
  return ((float_t)lsb *0.732f);
}

float_t lsm9ds1_from_fs245dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb *8.75f);
}

float_t lsm9ds1_from_fs500dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb *17.50f);
}

float_t lsm9ds1_from_fs2000dps_to_mdps(int16_t lsb)
{
  return ((float_t)lsb *70.0f);
}

float_t lsm9ds1_from_fs4gauss_to_mG(int16_t lsb)
{
  return ((float_t)lsb *0.14f);
}

float_t lsm9ds1_from_fs8gauss_to_mG(int16_t lsb)
{
  return ((float_t)lsb *0.29f);
}

float_t lsm9ds1_from_fs12gauss_to_mG(int16_t lsb)
{
  return ((float_t)lsb *0.43f);
}

float_t lsm9ds1_from_fs16gauss_to_mG(int16_t lsb)
{
  return ((float_t)lsb *0.58f);
}

float_t lsm9ds1_from_lsb_to_celsius(int16_t lsb)
{
  return (((float_t)lsb / 16.0f) + 25.0f);
}

