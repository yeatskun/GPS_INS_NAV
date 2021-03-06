/*
 * ITG3200.h
 *
 *  Created on: Jun 6, 2016
 *      Author: Rafi
 */

#ifndef ITG3200_H_
#define ITG3200_H_

#define WHO_AM_I_REG 			0x0
#define SAMPLE_RATE_DIV_REG   	0x15
#define DLPF_FULL_SCALE_REG   	0x16
#define INTERRUPTS_CFG_REG    	0x17
#define INTERRUPTS_STATUS_REG 	0x1A
#define TEMP_OUT_HIGH_REG	  	0x1B
#define TEMP_OUT_LOW_REG 	  	0x1C
#define GYRO_XOUT_HIGH_REG 		0x1D
#define GYRO_XOUT_LOW_REG 		0x1E
#define GYRO_YOUT_HIGH_REG 		0x1F
#define GYRO_YOUT_LOW_REG_REG 	0x20
#define GYRO_ZOUT_HIGH_REG 		0x21
#define GYRO_ZOUT_LOW_REG 		0x22
#define POWER_MNG_REG 			0x62

#define SAMPLE_RATE_DIV_VALUE  0
#define DLPF_FULL_SCALE_VALUE ((FS_SEL << 3 )| DLPF_CFG)
#define INTERRUPTS_CFG_VALUE  (INT_CFG_ACTL | INT_CFG_OPEN | INT_CFG_LATCH | INT_CFG_ANYRD | INT_CFG_ITG_RDY | INT_CFG_RAW_RDY)
#define POWER_MNG_VALUE (PM_H_RESET | PM_SLEEP | PM_STBY_XG | PM_STBY_YG | PM_STBY_ZG | CLK_SEL)

#define INT_CFG_ACTL    (0x0 << 7)
#define INT_CFG_OPEN    (0x0 << 6)
#define INT_CFG_LATCH   (0x1 << 5)
#define INT_CFG_ANYRD   (0x0 << 4)
#define INT_CFG_ITG_RDY (0x1 << 2)
#define INT_CFG_RAW_RDY  0x1

#define FS_SEL 0x3
#define DLPF_CFG 0x0

#define INT_STATUS_RAW_RDY  0x1
#define INT_STATUS_ITG_RDY  0x4

#define PM_H_RESET (0x1 << 7)
#define PM_SLEEP   (0x0 << 6)
#define PM_STBY_XG (0x0 << 5)
#define PM_STBY_YG (0x0 << 4)
#define PM_STBY_ZG (0x0 << 3)
#define CLK_SEL	  	0x0


#define GYR_SCALE_FACTOR 14.375

typedef struct {
	double Wr;
	double Wp;
	double Wy;
} Gyr_local_data_str;

int ITG3200_read_gyrdata(char addr, Gyr_local_data_str* gyr_data);
int init_ITG3200(char addr);

#endif /* ITG3200_H_ */
