/*
* Copyright (C) 2016 MediaTek Inc.
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
* See http://www.gnu.org/licenses/gpl-2.0.html for more details.
*/

#ifndef __CUST_ACC_H__
#define __CUST_ACC_H__

#include <linux/types.h>
#include <linux/of.h>
#define G_CUST_I2C_ADDR_NUM 2

struct acc_hw {
	int i2c_num;		/*!< the i2c bus used by the chip */
	int direction;		/*!< the direction of the chip */
	int power_id;		/*!< the VDD LDO ID of the chip, MT6516_POWER_NONE means the power is always on */
	int power_vol;		/*!< the VDD Power Voltage used by the chip */
	int firlen;		/*!< the length of low pass filter */
	int (*power)(struct acc_hw *hw, unsigned int on, char *devname);
	/*!< i2c address list,for chips which has different addresses with different HW layout */
	unsigned char i2c_addr[G_CUST_I2C_ADDR_NUM];
	int power_vio_id;	/*!< the VIO LDO ID of the chip, MT6516_POWER_NONE means the power is always on */
	int power_vio_vol;	/*!< the VIO Power Voltage used by the chip */
	bool is_batch_supported;
	int calib_enable;
	int auto_calib_enable;
};

int get_accel_dts_func(struct device_node *node, struct acc_hw*);
//struct acc_hw *get_accel_dts_func(const char *, struct acc_hw*);
#endif
