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

/**
  * @}
  *
  */

/**
  * @defgroup   LSM9DS1_Data_generation
  * @brief      This section groups all the functions concerning data
  *             generation
  * @{
  *
  */

/**
  * @brief  Gyroscope full-scale selection.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of "fs_g" in reg LSM9DS1.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_full_scale_set(lsm9ds1_ctx_t *ctx, lsm9ds1_gy_fs_t val)
{
  lsm9ds1_ctrl_reg1_g_t ctrl_reg1_g;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_G, (uint8_t*)&ctrl_reg1_g, 1);
  if(ret == 0){
    ctrl_reg1_g.fs_g = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG1_G,
                            (uint8_t*)&ctrl_reg1_g, 1);
  }
  return ret;
}

/**
  * @brief  Gyroscope full-scale selection.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of fs_g in reg CTRL_REG1_G.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_full_scale_get(lsm9ds1_ctx_t *ctx, lsm9ds1_gy_fs_t *val)
{
  lsm9ds1_ctrl_reg1_g_t ctrl_reg1_g;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_G, (uint8_t*)&ctrl_reg1_g, 1);
  switch (ctrl_reg1_g.fs_g){
    case LSM9DS1_245dps:
      *val = LSM9DS1_245dps;
      break;
    case LSM9DS1_500dps:
      *val = LSM9DS1_500dps;
      break;
    case LSM9DS1_2000dps:
      *val = LSM9DS1_2000dps;
      break;
    default:
      *val = LSM9DS1_245dps;
      break;
  }
  return ret;
}

/**
  * @brief  Data rate selection when both the accelerometer and gyroscope
  *         are activated.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of "odr_g" in reg LSM9DS1.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_imu_data_rate_set(lsm9ds1_ctx_t *ctx, lsm9ds1_imu_odr_t val)
{
  lsm9ds1_ctrl_reg1_g_t ctrl_reg1_g;
  lsm9ds1_ctrl_reg6_xl_t ctrl_reg6_xl;
  lsm9ds1_ctrl_reg3_g_t ctrl_reg3_g;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_G, (uint8_t*)&ctrl_reg1_g, 1);
  if(ret == 0){
    ctrl_reg1_g.odr_g = (uint8_t)val & 0x07U;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG1_G,
                            (uint8_t*)&ctrl_reg1_g, 1);
  }
  if(ret == 0){
  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG6_XL,
                         (uint8_t*)&ctrl_reg6_xl, 1);
  }
  if(ret == 0){
    ctrl_reg6_xl.odr_xl = (((uint8_t)val & 0x70U) >> 4);
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG6_XL,
                            (uint8_t*)&ctrl_reg6_xl, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG3_G,
                           (uint8_t*)&ctrl_reg3_g, 1);
  }
  if(ret == 0){
    ctrl_reg3_g.lp_mode = (((uint8_t)val & 0x80U) >> 7);
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG3_G,
                            (uint8_t*)&ctrl_reg3_g, 1);
  }

  return ret;
}

/**
  * @brief  Data rate selection when both the accelerometer and gyroscope
  *         are activated.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of odr_g in reg CTRL_REG1_G.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_imu_data_rate_get(lsm9ds1_ctx_t *ctx, lsm9ds1_imu_odr_t *val)
{
  lsm9ds1_ctrl_reg1_g_t ctrl_reg1_g;
  lsm9ds1_ctrl_reg6_xl_t ctrl_reg6_xl;
  lsm9ds1_ctrl_reg3_g_t ctrl_reg3_g;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_G, (uint8_t*)&ctrl_reg1_g, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG6_XL,
                           (uint8_t*)&ctrl_reg6_xl, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG3_G,
                           (uint8_t*)&ctrl_reg3_g, 1);
  }
  switch ((ctrl_reg3_g.lp_mode << 7) | (ctrl_reg6_xl.odr_xl << 4) |
          ctrl_reg1_g.odr_g){
    case LSM9DS1_IMU_OFF:
      *val = LSM9DS1_IMU_OFF;
      break;
    case LSM9DS1_GY_OFF_XL_10Hz:
      *val = LSM9DS1_GY_OFF_XL_10Hz;
      break;
    case LSM9DS1_GY_OFF_XL_50Hz:
      *val = LSM9DS1_GY_OFF_XL_50Hz;
      break;
    case LSM9DS1_GY_OFF_XL_119Hz:
      *val = LSM9DS1_GY_OFF_XL_119Hz;
      break;
    case LSM9DS1_GY_OFF_XL_238Hz:
      *val = LSM9DS1_GY_OFF_XL_238Hz;
      break;
    case LSM9DS1_GY_OFF_XL_476Hz:
      *val = LSM9DS1_GY_OFF_XL_476Hz;
      break;
    case LSM9DS1_GY_OFF_XL_952Hz:
      *val = LSM9DS1_GY_OFF_XL_952Hz;
      break;
    case LSM9DS1_XL_OFF_GY_14Hz9:
      *val = LSM9DS1_XL_OFF_GY_14Hz9;
      break;
    case LSM9DS1_XL_OFF_GY_59Hz5:
      *val = LSM9DS1_XL_OFF_GY_59Hz5;
      break;
    case LSM9DS1_XL_OFF_GY_119Hz:
      *val = LSM9DS1_XL_OFF_GY_119Hz;
      break;
    case LSM9DS1_XL_OFF_GY_238Hz:
      *val = LSM9DS1_XL_OFF_GY_238Hz;
      break;
    case LSM9DS1_XL_OFF_GY_476Hz:
      *val = LSM9DS1_XL_OFF_GY_476Hz;
      break;
    case LSM9DS1_XL_OFF_GY_952Hz:
      *val = LSM9DS1_XL_OFF_GY_952Hz;
      break;
    case LSM9DS1_IMU_14Hz9:
      *val = LSM9DS1_IMU_14Hz9;
      break;
    case LSM9DS1_IMU_59Hz5:
      *val = LSM9DS1_IMU_59Hz5;
      break;
    case LSM9DS1_IMU_119Hz:
      *val = LSM9DS1_IMU_119Hz;
      break;
    case LSM9DS1_IMU_238Hz:
      *val = LSM9DS1_IMU_238Hz;
      break;
    case LSM9DS1_IMU_476Hz:
      *val = LSM9DS1_IMU_476Hz;
      break;
    case LSM9DS1_IMU_952Hz:
      *val = LSM9DS1_IMU_952Hz;
      break;
    case LSM9DS1_XL_OFF_GY_14Hz9_LP:
      *val = LSM9DS1_XL_OFF_GY_14Hz9_LP;
      break;
    case LSM9DS1_XL_OFF_GY_59Hz5_LP:
      *val = LSM9DS1_XL_OFF_GY_59Hz5_LP;
      break;
    case LSM9DS1_XL_OFF_GY_119Hz_LP:
      *val = LSM9DS1_XL_OFF_GY_119Hz_LP;
      break;
    case LSM9DS1_IMU_14Hz9_LP:
      *val = LSM9DS1_IMU_14Hz9_LP;
      break;
    case LSM9DS1_IMU_59Hz5_LP:
      *val = LSM9DS1_IMU_59Hz5_LP;
      break;
    case LSM9DS1_IMU_119Hz_LP:
      *val = LSM9DS1_IMU_119Hz_LP;
      break;
    default:
      *val = LSM9DS1_IMU_OFF;
    break;
  }

  return ret;
}

/**
  * @brief   Configure gyro orientation.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Directional user orientation selection.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_orient_set(lsm9ds1_ctx_t *ctx, lsm9ds1_gy_orient_t val)
{
  lsm9ds1_orient_cfg_g_t orient_cfg_g;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_ORIENT_CFG_G,
                         (uint8_t*)&orient_cfg_g, 1);
  if(ret == 0) {
    orient_cfg_g.orient   = val.orient;
    orient_cfg_g.signx_g  = val.signx_g;
    orient_cfg_g.signy_g  = val.signy_g;
    orient_cfg_g.signz_g  = val.signz_g;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_ORIENT_CFG_G, (uint8_t*)&orient_cfg_g, 1);
  }
  return ret;
}

/**
  * @brief   Configure gyro orientation.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val     Directional user orientation selection.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_orient_get(lsm9ds1_ctx_t *ctx, lsm9ds1_gy_orient_t *val)
{
  lsm9ds1_orient_cfg_g_t orient_cfg_g;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_ORIENT_CFG_G,
                         (uint8_t*)&orient_cfg_g, 1);
  val->orient = orient_cfg_g.orient;
  val->signz_g = orient_cfg_g.signz_g;
  val->signy_g = orient_cfg_g.signy_g;
  val->signx_g = orient_cfg_g.signx_g;

  return ret;
}

/**
  * @brief  Gyroscope new data available.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Iet the values of "gda" in reg STATUS_REG.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_flag_data_ready_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_status_reg_t status_reg;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_STATUS_REG, (uint8_t*)&status_reg, 1);
  *val = status_reg.gda;

  return ret;
}


/**
  * @brief  Enable gyroscope axis.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val     Gyroscope’s pitch axis (X) output enable.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_axis_set(lsm9ds1_ctx_t *ctx, lsm9ds1_gy_axis_t val)
{
  lsm9ds1_ctrl_reg4_t ctrl_reg4;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG4, (uint8_t*)&ctrl_reg4, 1);
  if(ret == 0) {
    ctrl_reg4.xen_g = val.xen_g;
    ctrl_reg4.yen_g = val.yen_g;
    ctrl_reg4.zen_g = val.zen_g;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG4, (uint8_t*)&ctrl_reg4, 1);
  }
  return ret;
}

/**
  * @brief  Enable gyroscope axis.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val     Gyroscope’s pitch axis (X) output enable.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_axis_get(lsm9ds1_ctx_t *ctx, lsm9ds1_gy_axis_t *val)
{
  lsm9ds1_ctrl_reg4_t ctrl_reg4;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG4, (uint8_t*)&ctrl_reg4, 1);
  val->xen_g = ctrl_reg4.xen_g;
  val->yen_g = ctrl_reg4.yen_g;
  val->zen_g = ctrl_reg4.zen_g;

  return ret;
}

/**
  * @brief  Blockdataupdate.[set]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Change the values of bdu in reg CTRL_REG8.
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_block_data_update_set(lsm9ds1_ctx_t *ctx_mag,
                                      lsm9ds1_ctx_t *ctx_imu, uint8_t val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  lsm9ds1_ctrl_reg5_m_t ctrl_reg5_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ctrl_reg8.bdu = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG5_M,
                           (uint8_t*)&ctrl_reg5_m, 1);
  }
  if(ret == 0){
    ctrl_reg5_m.fast_read = (uint8_t)(~val);
    ctrl_reg5_m.bdu = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_mag, LSM9DS1_CTRL_REG5_M,
                            (uint8_t*)&ctrl_reg5_m, 1);
  }

  return ret;
}

/**
  * @brief  Blockdataupdate.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Get the values of bdu in reg CTRL_REG8.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_block_data_update_get(lsm9ds1_ctx_t *ctx_mag,
                                      lsm9ds1_ctx_t *ctx_imu, uint8_t *val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  lsm9ds1_ctrl_reg5_m_t ctrl_reg5_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG5_M, (uint8_t*)&ctrl_reg5_m, 1);
    *val = (uint8_t)(ctrl_reg5_m.bdu & ctrl_reg8.bdu);
  }
  return ret;
}

/**
  * @brief  This register is a 16-bit register and represents the X offset
  *         used to compensate environmental effects (data is expressed as
  *         two’s complement).[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  buff   Buffer that stores data to be write.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_offset_set(lsm9ds1_ctx_t *ctx, uint8_t *buff)
{
  int32_t ret;
  ret = lsm9ds1_write_reg(ctx, LSM9DS1_OFFSET_X_REG_L_M, buff, 6);
  return ret;
}

/**
  * @brief  This register is a 16-bit register and represents the X offset
  *         used to compensate environmental effects (data is expressed as
  *         two’s complement).[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  buff   Buffer that stores data read.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_offset_get(lsm9ds1_ctx_t *ctx, uint8_t *buff)
{
  int32_t ret;
  ret = lsm9ds1_read_reg(ctx, LSM9DS1_OFFSET_X_REG_L_M, buff, 6);
  return ret;
}

/**
  * @brief  Magnetometer data rate selection.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of "fast_odr" in reg LSM9DS1.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_data_rate_set(lsm9ds1_ctx_t *ctx,
                                  lsm9ds1_mag_data_rate_t val)
{
  lsm9ds1_ctrl_reg1_m_t ctrl_reg1_m;
  lsm9ds1_ctrl_reg3_m_t ctrl_reg3_m;
  lsm9ds1_ctrl_reg4_m_t ctrl_reg4_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_M, (uint8_t*)&ctrl_reg1_m, 1);
  if(ret == 0){
    ctrl_reg1_m.fast_odr = (((uint8_t)val & 0x08U) >> 3);
    ctrl_reg1_m._do = ((uint8_t)val & 0x07U);
    ctrl_reg1_m.om = (((uint8_t)val & 0x30U) >> 4);
    ctrl_reg1_m.temp_comp = PROPERTY_ENABLE;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG1_M,
                            (uint8_t*)&ctrl_reg1_m, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG3_M,
                           (uint8_t*)&ctrl_reg3_m, 1);
  }
  if(ret == 0){
    ctrl_reg3_m.md = (((uint8_t)val & 0xC0U) >> 6);
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG3_M,
                            (uint8_t*)&ctrl_reg3_m, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG4_M, (uint8_t*)&ctrl_reg4_m, 1);
  }
  if(ret == 0){
    ctrl_reg4_m.omz = (((uint8_t)val & 0x30U) >> 4);;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG4_M,
                            (uint8_t*)&ctrl_reg4_m, 1);
  }
  return ret;
}

/**
  * @brief  Magnetometer data rate selection.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of fast_odr in reg CTRL_REG1_M.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_data_rate_get(lsm9ds1_ctx_t *ctx,
                                  lsm9ds1_mag_data_rate_t *val)
{
  lsm9ds1_ctrl_reg1_m_t ctrl_reg1_m;
  lsm9ds1_ctrl_reg3_m_t ctrl_reg3_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_M, (uint8_t*)&ctrl_reg1_m, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG3_M, (uint8_t*)&ctrl_reg3_m, 1);
  }
  switch ((ctrl_reg3_m.md << 6) | (ctrl_reg1_m.om << 4) |
          (ctrl_reg1_m.fast_odr << 3) | ctrl_reg1_m._do){
    case LSM9DS1_MAG_POWER_DOWN:
      *val = LSM9DS1_MAG_POWER_DOWN;
      break;
    case LSM9DS1_MAG_LP_0Hz625:
      *val = LSM9DS1_MAG_LP_0Hz625;
      break;
    case LSM9DS1_MAG_LP_1Hz25:
      *val = LSM9DS1_MAG_LP_1Hz25;
      break;
    case LSM9DS1_MAG_LP_2Hz5:
      *val = LSM9DS1_MAG_LP_2Hz5;
      break;
    case LSM9DS1_MAG_LP_5Hz:
      *val = LSM9DS1_MAG_LP_5Hz;
      break;
    case LSM9DS1_MAG_LP_10Hz:
      *val = LSM9DS1_MAG_LP_10Hz;
      break;
    case LSM9DS1_MAG_LP_20Hz:
      *val = LSM9DS1_MAG_LP_20Hz;
      break;
    case LSM9DS1_MAG_LP_40Hz:
      *val = LSM9DS1_MAG_LP_40Hz;
      break;
    case LSM9DS1_MAG_LP_80Hz:
      *val = LSM9DS1_MAG_LP_80Hz;
      break;
    case LSM9DS1_MAG_MP_0Hz625:
      *val = LSM9DS1_MAG_MP_0Hz625;
      break;
    case LSM9DS1_MAG_MP_1Hz25:
      *val = LSM9DS1_MAG_MP_1Hz25;
      break;
    case LSM9DS1_MAG_MP_2Hz5:
      *val = LSM9DS1_MAG_MP_2Hz5;
      break;
    case LSM9DS1_MAG_MP_5Hz:
      *val = LSM9DS1_MAG_MP_5Hz;
      break;
    case LSM9DS1_MAG_MP_10Hz:
      *val = LSM9DS1_MAG_MP_10Hz;
      break;
    case LSM9DS1_MAG_MP_20Hz:
      *val = LSM9DS1_MAG_MP_20Hz;
      break;
    case LSM9DS1_MAG_MP_40Hz:
      *val = LSM9DS1_MAG_MP_40Hz;
      break;
    case LSM9DS1_MAG_MP_80Hz:
      *val = LSM9DS1_MAG_MP_80Hz;
      break;
    case LSM9DS1_MAG_HP_0Hz625:
      *val = LSM9DS1_MAG_HP_0Hz625;
      break;
    case LSM9DS1_MAG_HP_1Hz25:
      *val = LSM9DS1_MAG_HP_1Hz25;
      break;
    case LSM9DS1_MAG_HP_2Hz5:
      *val = LSM9DS1_MAG_HP_2Hz5;
      break;
    case LSM9DS1_MAG_HP_5Hz:
      *val = LSM9DS1_MAG_HP_5Hz;
      break;
    case LSM9DS1_MAG_HP_10Hz:
      *val = LSM9DS1_MAG_HP_10Hz;
      break;
    case LSM9DS1_MAG_HP_20Hz:
      *val = LSM9DS1_MAG_HP_20Hz;
      break;
    case LSM9DS1_MAG_HP_40Hz:
      *val = LSM9DS1_MAG_HP_40Hz;
      break;
    case LSM9DS1_MAG_HP_80Hz:
      *val = LSM9DS1_MAG_HP_80Hz;
      break;
    case LSM9DS1_MAG_UHP_0Hz625:
      *val = LSM9DS1_MAG_UHP_0Hz625;
      break;
    case LSM9DS1_MAG_UHP_1Hz25:
      *val = LSM9DS1_MAG_UHP_1Hz25;
      break;
    case LSM9DS1_MAG_UHP_2Hz5:
      *val = LSM9DS1_MAG_UHP_2Hz5;
      break;
    case LSM9DS1_MAG_UHP_5Hz:
      *val = LSM9DS1_MAG_UHP_5Hz;
      break;
    case LSM9DS1_MAG_UHP_10Hz:
      *val = LSM9DS1_MAG_UHP_10Hz;
      break;
    case LSM9DS1_MAG_UHP_20Hz:
      *val = LSM9DS1_MAG_UHP_20Hz;
      break;
    case LSM9DS1_MAG_UHP_40Hz:
      *val = LSM9DS1_MAG_UHP_40Hz;
      break;
    case LSM9DS1_MAG_UHP_80Hz:
      *val = LSM9DS1_MAG_UHP_80Hz;
      break;
    case LSM9DS1_MAG_UHP_155Hz:
      *val = LSM9DS1_MAG_UHP_155Hz;
      break;
    case LSM9DS1_MAG_HP_300Hz:
      *val = LSM9DS1_MAG_HP_300Hz;
      break;
    case LSM9DS1_MAG_MP_560Hz:
      *val = LSM9DS1_MAG_MP_560Hz;
      break;
    case LSM9DS1_MAG_LP_1000Hz:
      *val = LSM9DS1_MAG_LP_1000Hz;
      break;
    case LSM9DS1_MAG_ONE_SHOT:
      *val = LSM9DS1_MAG_ONE_SHOT;
      break;
    default:
      *val = LSM9DS1_MAG_POWER_DOWN;
      break;
  }
  return ret;
}

/**
  * @brief  Magnetometer full Scale Selection.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of "fs" in reg LSM9DS1.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_full_scale_set(lsm9ds1_ctx_t *ctx, lsm9ds1_mag_fs_t val)
{
  lsm9ds1_ctrl_reg2_m_t ctrl_reg2_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG2_M, (uint8_t*)&ctrl_reg2_m, 1);
  if(ret == 0){
    ctrl_reg2_m.fs = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG2_M,
                            (uint8_t*)&ctrl_reg2_m, 1);
  }
  return ret;
}

/**
  * @brief  Magnetometer full scale selection.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of fs in reg CTRL_REG2_M.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_full_scale_get(lsm9ds1_ctx_t *ctx, lsm9ds1_mag_fs_t *val)
{
  lsm9ds1_ctrl_reg2_m_t ctrl_reg2_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG2_M, (uint8_t*)&ctrl_reg2_m, 1);
  switch (ctrl_reg2_m.fs){
    case LSM9DS1_4Ga:
      *val = LSM9DS1_4Ga;
      break;
    case LSM9DS1_8Ga:
      *val = LSM9DS1_8Ga;
      break;
    case LSM9DS1_12Ga:
      *val = LSM9DS1_12Ga;
      break;
    case LSM9DS1_16Ga:
      *val = LSM9DS1_16Ga;
      break;
    default:
      *val = LSM9DS1_4Ga;
      break;
  }
  return ret;
}

/**
  * @brief  New data available from magnetometer.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Iet the values of "zyxda" in reg STATUS_REG_M.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_flag_data_ready_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_status_reg_m_t status_reg_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_STATUS_REG_M,
                         (uint8_t*)&status_reg_m, 1);
  *val = status_reg_m.zyxda;

  return ret;
}

/**
  * @brief  Angular rate sensor. The value is expressed as a 16-bit word in
  *         two’s complement.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  buff   Buffer that stores the data read.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_angular_rate_raw_get(lsm9ds1_ctx_t *ctx, uint8_t *buff)
{
  int32_t ret;
  ret = lsm9ds1_read_reg(ctx, LSM9DS1_OUT_X_L_G, buff, 6);
  return ret;
}

/**
  * @brief  Magnetic sensor. The value is expressed as a 16-bit word in
  *         two’s complement.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  buff   Buffer that stores the data read.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_magnetic_raw_get(lsm9ds1_ctx_t *ctx, uint8_t *buff)
{
  int32_t ret;
  ret = lsm9ds1_read_reg(ctx, LSM9DS1_OUT_X_L_M, buff, 6);
  return ret;
}

/**
  * @brief  Internal measurement range overflow on magnetic value.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Iet the values of "mroi" in reg INT_SRC_M.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_magnetic_overflow_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_int_src_m_t int_src_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_INT_SRC_M, (uint8_t*)&int_src_m, 1);
  *val = int_src_m.mroi;

  return ret;
}

/**
  * @}
  *
  */

/**
  * @defgroup    LSM9DS1_Common
  * @brief       This section groups common usefull functions.
  * @{
  *
  */

/**
  * @brief  DeviceWhoamI.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  buff      Buffer that stores the data read.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_id_get(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                           lsm9ds1_id_t *buff)
{
  int32_t ret;
  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_WHO_AM_I,
                         (uint8_t*)&(buff->imu), 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_WHO_AM_I_M,
                           (uint8_t*)&(buff->mag), 1);
  }
  return ret;
}

/**
  * @brief  Device status register.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Device status registers.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_status_get(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                               lsm9ds1_status_t *val)
{
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_STATUS_REG,
                         (uint8_t*)&(val->status_imu), 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_STATUS_REG_M,
                           (uint8_t*)&(val->status_mag), 1);
  }

  return ret;
}

/**
  * @brief  Software reset. Restore the default values in user registers.[set]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val    Change the values of sw_reset in reg CTRL_REG8.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_reset_set(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                              uint8_t val)
{
  lsm9ds1_ctrl_reg2_m_t ctrl_reg2_m;
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ctrl_reg8.sw_reset = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_imu, LSM9DS1_CTRL_REG8,
                            (uint8_t*)&ctrl_reg8, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG2_M,
                           (uint8_t*)&ctrl_reg2_m, 1);
  }
  if(ret == 0){
    ctrl_reg2_m.soft_rst = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_mag, LSM9DS1_CTRL_REG2_M,
                            (uint8_t*)&ctrl_reg2_m, 1);
  }

  return ret;
}

/**
  * @brief  Software reset. Restore the default values in user registers.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Get the values of sw_reset in reg CTRL_REG8.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_reset_get(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                              uint8_t *val)
{
  lsm9ds1_ctrl_reg2_m_t ctrl_reg2_m;
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG2_M,
                           (uint8_t*)&ctrl_reg2_m, 1);
    *val = (uint8_t)(ctrl_reg2_m.soft_rst & ctrl_reg8.sw_reset);
  }
  return ret;
}

/**
  * @brief  Big/Little Endian data selection.[set]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Change the values of "ble" in reg LSM9DS1.
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_data_format_set(lsm9ds1_ctx_t *ctx_mag,
                                    lsm9ds1_ctx_t *ctx_imu,
                                    lsm9ds1_ble_t val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  lsm9ds1_ctrl_reg4_m_t ctrl_reg4_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8,
                         (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ctrl_reg8.ble = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_imu, LSM9DS1_CTRL_REG8,
                            (uint8_t*)&ctrl_reg8, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG4_M,
                           (uint8_t*)&ctrl_reg4_m, 1);
  }
  if(ret == 0){
    ctrl_reg4_m.ble = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_mag, LSM9DS1_CTRL_REG4_M,
                            (uint8_t*)&ctrl_reg4_m, 1);
  }
  return ret;
}

/**
  * @brief  Big/Little Endian data selection.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Get the values of ble in reg CTRL_REG8.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_data_format_get(lsm9ds1_ctx_t *ctx_mag,
                                    lsm9ds1_ctx_t *ctx_imu,
                                    lsm9ds1_ble_t *val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  lsm9ds1_ctrl_reg4_m_t ctrl_reg4_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG4_M,
                           (uint8_t*)&ctrl_reg4_m, 1);
  }
  switch (ctrl_reg8.ble & ctrl_reg4_m.ble){
    case LSM9DS1_LSB_LOW_ADDRESS:
      *val = LSM9DS1_LSB_LOW_ADDRESS;
      break;
    case LSM9DS1_MSB_LOW_ADDRESS:
      *val = LSM9DS1_MSB_LOW_ADDRESS;
      break;
    default:
      *val = LSM9DS1_LSB_LOW_ADDRESS;
      break;
  }
  return ret;
}

/**
  * @brief  Reboot memory content. Reload the calibration parameters.[set]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Change the values of boot in reg CTRL_REG8.
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_boot_set(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                             uint8_t val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  lsm9ds1_ctrl_reg2_m_t ctrl_reg2_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8,
                         (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ctrl_reg8.boot = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_imu, LSM9DS1_CTRL_REG8,
                            (uint8_t*)&ctrl_reg8, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG2_M,
                           (uint8_t*)&ctrl_reg2_m, 1);
  }
  if(ret == 0){
    ctrl_reg2_m.reboot = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_mag, LSM9DS1_CTRL_REG2_M,
                            (uint8_t*)&ctrl_reg2_m, 1);
  }
  return ret;
}

/**
  * @brief  Reboot memory content. Reload the calibration parameters.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Get the values of boot in reg CTRL_REG8.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_dev_boot_get(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                             uint8_t *val)
{
  lsm9ds1_ctrl_reg2_m_t ctrl_reg2_m;
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
  ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG2_M,
                         (uint8_t*)&ctrl_reg2_m, 1);
    *val = (uint8_t)ctrl_reg2_m.reboot & ctrl_reg8.boot;
  }
  return ret;
}

/**
  * @}
  *
  */

/**
  * @defgroup     LSM9DS1_Serial_interface
  * @brief        This section groups all the functions concerning main
  *               serial interface management (not auxiliary)
  * @{
  *
  */

/**
  * @brief  Register address automatically incremented during a multiple
  *         byte access with a serial interface.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of "if_add_inc" in reg LSM9DS1.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_auto_increment_set(lsm9ds1_ctx_t *ctx, uint8_t val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ctrl_reg8.if_add_inc = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  }
  return ret;
}

/**
  * @brief  Register address automatically incremented during a multiple
  *         byte access with a serial interface.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of if_add_inc in reg CTRL_REG8.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_auto_increment_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  *val = (uint8_t)ctrl_reg8.if_add_inc;
  return ret;
}

/**
  * @brief  SPI Serial Interface Mode selection.[set]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Change the values of "sim" in reg LSM9DS1.
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_spi_mode_set(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                             lsm9ds1_sim_t val)
{
  lsm9ds1_ctrl_reg3_m_t ctrl_reg3_m;
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
    ctrl_reg8.sim = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  }
  if(ret == 0){
      ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG3_M,
                             (uint8_t*)&ctrl_reg3_m, 1);
  }
  if(ret == 0){
    ctrl_reg3_m.sim = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_mag, LSM9DS1_CTRL_REG3_M,
                            (uint8_t*)&ctrl_reg3_m, 1);
  }
  return ret;
}

/**
  * @brief  SPI Serial Interface Mode selection.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Get the values of sim in reg CTRL_REG8.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_spi_mode_get(lsm9ds1_ctx_t *ctx_mag, lsm9ds1_ctx_t *ctx_imu,
                             lsm9ds1_sim_t *val)
{
  lsm9ds1_ctrl_reg3_m_t ctrl_reg3_m;
  lsm9ds1_ctrl_reg8_t ctrl_reg8;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG8, (uint8_t*)&ctrl_reg8, 1);
  if(ret == 0){
      ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG3_M,
                             (uint8_t*)&ctrl_reg3_m, 1);
  }
  switch (ctrl_reg8.sim & ctrl_reg3_m.sim){
    case LSM9DS1_SPI_4_WIRE:
      *val = LSM9DS1_SPI_4_WIRE;
      break;
    case LSM9DS1_SPI_3_WIRE:
      *val = LSM9DS1_SPI_3_WIRE;
      break;
    default:
      *val = LSM9DS1_SPI_4_WIRE;
      break;
  }
  return ret;
}

/**
  * @brief  Enable / Disable I2C interface.[set]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Change the values of "i2c_disable" in reg LSM9DS1.
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_i2c_interface_set(lsm9ds1_ctx_t *ctx_mag,
                                  lsm9ds1_ctx_t *ctx_imu,
                                  lsm9ds1_i2c_dis_t val)
{
  lsm9ds1_ctrl_reg3_m_t ctrl_reg3_m;
  lsm9ds1_ctrl_reg9_t ctrl_reg9;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  if(ret == 0){
    ctrl_reg9.i2c_disable = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_imu, LSM9DS1_CTRL_REG9,
                            (uint8_t*)&ctrl_reg9, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG3_M,
                           (uint8_t*)&ctrl_reg3_m, 1);
  }
  if(ret == 0){
    ctrl_reg3_m.i2c_disable = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx_mag, LSM9DS1_CTRL_REG3_M,
                            (uint8_t*)&ctrl_reg3_m, 1);
  }
  return ret;
}

/**
  * @brief  Enable / Disable I2C interface.[get]
  *
  * @param  ctx_mag   Read / write magnetometer interface definitions.(ptr)
  * @param  ctx_imu   Read / write imu interface definitions.(ptr)
  * @param  val       Get the values of i2c_disable in reg CTRL_REG9.(ptr)
  * @retval           Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_i2c_interface_get(lsm9ds1_ctx_t *ctx_mag,
                                  lsm9ds1_ctx_t *ctx_imu,
                                  lsm9ds1_i2c_dis_t *val)
{
  lsm9ds1_ctrl_reg3_m_t ctrl_reg3_m;
  lsm9ds1_ctrl_reg9_t ctrl_reg9;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx_imu, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx_mag, LSM9DS1_CTRL_REG3_M,
                           (uint8_t*)&ctrl_reg3_m, 1);
  }
  switch (ctrl_reg9.i2c_disable & ctrl_reg3_m.i2c_disable){
    case LSM9DS1_I2C_ENABLE:
      *val = LSM9DS1_I2C_ENABLE;
      break;
    case LSM9DS1_I2C_DISABLE:
      *val = LSM9DS1_I2C_DISABLE;
      break;
    default:
      *val = LSM9DS1_I2C_ENABLE;
      break;
  }
  return ret;
}


/**
  * @}
  *
  */

/**
  * @defgroup     LSM9DS1_Fifo
  * @brief        This section group all the functions concerning the
  *               fifo usage
  * @{
  *
  */

/**
  * @brief  Sensing chain FIFO stop values memorization at threshold
  *         level.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of stop_on_fth in reg CTRL_REG9.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_stop_on_wtm_set(lsm9ds1_ctx_t *ctx, uint8_t val)
{
  lsm9ds1_ctrl_reg9_t ctrl_reg9;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  if(ret == 0){
    ctrl_reg9.stop_on_fth = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  }
  return ret;
}

/**
  * @brief  Sensing chain FIFO stop values memorization at
  *         threshold level.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of stop_on_fth in reg CTRL_REG9.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_stop_on_wtm_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_ctrl_reg9_t ctrl_reg9;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  *val = (uint8_t)ctrl_reg9.stop_on_fth;

  return ret;
}

/**
  * @brief  FIFO mode selection.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of "fifo_en" in reg LSM9DS1.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_mode_set(lsm9ds1_ctx_t *ctx, lsm9ds1_fifo_md_t val)
{
  lsm9ds1_ctrl_reg9_t ctrl_reg9;
  lsm9ds1_fifo_ctrl_t fifo_ctrl;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  if(ret == 0){
    ctrl_reg9.fifo_en = ( ( (uint8_t)val & 0x10U ) >> 4);
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  }
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_FIFO_CTRL, (uint8_t*)&fifo_ctrl, 1);
  }
  if(ret == 0){
    fifo_ctrl.fmode = ( (uint8_t)val & 0x0FU );
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_FIFO_CTRL, (uint8_t*)&fifo_ctrl, 1);
  }
  return ret;
}

/**
  * @brief  FIFO mode selection.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of fifo_en in reg CTRL_REG9.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_mode_get(lsm9ds1_ctx_t *ctx, lsm9ds1_fifo_md_t *val)
{
  lsm9ds1_ctrl_reg9_t ctrl_reg9;
  lsm9ds1_fifo_ctrl_t fifo_ctrl;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG9, (uint8_t*)&ctrl_reg9, 1);
  if(ret == 0){
    ret = lsm9ds1_read_reg(ctx, LSM9DS1_FIFO_CTRL, (uint8_t*)&fifo_ctrl, 1);
  }
  switch ((ctrl_reg9.fifo_en << 4) | ctrl_reg9.fifo_en){
    case LSM9DS1_FIFO_OFF:
      *val = LSM9DS1_FIFO_OFF;
      break;
    case LSM9DS1_BYPASS_MODE:
      *val = LSM9DS1_BYPASS_MODE;
      break;
    case LSM9DS1_FIFO_MODE:
      *val = LSM9DS1_FIFO_MODE;
      break;
    case LSM9DS1_STREAM_TO_FIFO_MODE:
      *val = LSM9DS1_STREAM_TO_FIFO_MODE;
      break;
    case LSM9DS1_BYPASS_TO_STREAM_MODE:
      *val = LSM9DS1_BYPASS_TO_STREAM_MODE;
      break;
    case LSM9DS1_STREAM_MODE:
      *val = LSM9DS1_STREAM_MODE;
      break;
    default:
      *val = LSM9DS1_FIFO_OFF;
      break;
  }

  return ret;
}

/**
  * @brief  FIFOfullstatus.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Iet the values of "fss" in reg FIFO_SRC.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_full_flag_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_fifo_src_t fifo_src;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_FIFO_SRC, (uint8_t*)&fifo_src, 1);
  *val = fifo_src.fss;

  return ret;
}

/**
  * @brief  Number of unread words (16-bit axes) stored in FIFO.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Iet the values of "fss" in reg FIFO_SRC.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_data_level_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_fifo_src_t fifo_src;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_FIFO_SRC, (uint8_t*)&fifo_src, 1);
  *val = fifo_src.fss;

  return ret;
}

/**
  * @brief  FIFO overrun status.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Iet the values of "ovrn" in reg FIFO_SRC.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_fifo_ovr_flag_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_fifo_src_t fifo_src;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_FIFO_SRC, (uint8_t*)&fifo_src, 1);
  *val = fifo_src.ovrn;

  return ret;
}

/**
  * @}
  *
  */

/**
  * @defgroup     LSM9DS1_Self_test
  * @brief        This section groups all the functions that manage self
  *               test configuration
  * @{
  *
  */

/**
  * @brief  Enable/disable self-test mode for accelerometer.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of st_xl in reg CTRL_REG10.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
/**
  * @brief  Enable/disable self-test mode for gyroscope.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of st_g in reg CTRL_REG10.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_self_test_set(lsm9ds1_ctx_t *ctx, uint8_t val)
{
  lsm9ds1_ctrl_reg10_t ctrl_reg10;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG10, (uint8_t*)&ctrl_reg10, 1);
  if(ret == 0){
    ctrl_reg10.st_g = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG10, (uint8_t*)&ctrl_reg10, 1);
  }
  return ret;
}

/**
  * @brief  Enable/disable self-test mode for gyroscope.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of st_g in reg CTRL_REG10.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_gy_self_test_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_ctrl_reg10_t ctrl_reg10;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG10, (uint8_t*)&ctrl_reg10, 1);
  *val = (uint8_t)ctrl_reg10.st_g;

  return ret;
}

/**
  * @brief  Enable/disable self-test mode for magnatic sensor.[set]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Change the values of st in reg CTRL_REG1_M.
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_self_test_set(lsm9ds1_ctx_t *ctx, uint8_t val)
{
  lsm9ds1_ctrl_reg1_m_t ctrl_reg1_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_M, (uint8_t*)&ctrl_reg1_m, 1);
  if(ret == 0){
    ctrl_reg1_m.st = (uint8_t)val;
    ret = lsm9ds1_write_reg(ctx, LSM9DS1_CTRL_REG1_M,
                            (uint8_t*)&ctrl_reg1_m, 1);
  }
  return ret;
}

/**
  * @brief  Enable/disable self-test mode for magnatic sensor.[get]
  *
  * @param  ctx    Read / write interface definitions.(ptr)
  * @param  val    Get the values of st in reg CTRL_REG1_M.(ptr)
  * @retval        Interface status (MANDATORY: return 0 -> no Error).
  *
  */
int32_t lsm9ds1_mag_self_test_get(lsm9ds1_ctx_t *ctx, uint8_t *val)
{
  lsm9ds1_ctrl_reg1_m_t ctrl_reg1_m;
  int32_t ret;

  ret = lsm9ds1_read_reg(ctx, LSM9DS1_CTRL_REG1_M, (uint8_t*)&ctrl_reg1_m, 1);
  *val = (uint8_t)ctrl_reg1_m.st;

  return ret;
}

