/*
 * infrastructure.c
 *
 *  Created on: 11  2017
 *      Author: sahiadl
 *
 *      this file includes the infrastructure code.
 *      thie file contains functions that return the data in a manner that can be proccessed and convert to relevant units.
 *
 *      each function bring the data from the relevant device
 *      and sends it to units converter.
 *      for example:
 *      read data from gyroscope in lsb/sec
 *     	and converts it to rad/sec
 */



#include "includes/std_inc.h"
#include "includes/inc.h"
#include "includes/ex_common.h"
#include "includes/driverlib.h"
#include "includes/parameters.h"
#include "ff.h"

#include "board/board.h"
#include "includes/infrastructure.h"
#include "interfaces/terminal.h"


void init_board_and_sensors(){
	BoardInit();
	PinMuxConfig();

	init_HMC5883(MAG_ADDR, true);
	if(init_ADXL345(ACC_ADDR)<0){while(1){UART_PRINT("!!! acc I2c Error\n\r");}}
	if(init_ITG3200(GYR_ADDR)<0){while(1){UART_PRINT("!!! gyr I2c Error\n\r");}}
	init_MPL115A2();
	init_ds2401();
	init_SD_card();
	SD_write_file("hello.txt", "my name is", strlen("my name is"), SD_CREATE_AND_DELETE);

	GPS_on();
	GPS_off();

	InitTerm();
	ClearTerm();
}


/******************************************************/
//magnetometer read data functions
/******************************************************/
void get_mag_data(mag_input_data_str* mag_query){
	Mag_inner_data_str mag_data;
	HMC5883_read_magdata(MAG_ADDR, &mag_data );
	convert_mag_raw_data_2_units(&mag_data); //currently not used because only direction matters.
	copy_mag_data_2_algorithm(mag_query, mag_data);
}

void convert_mag_raw_data_2_units(Mag_inner_data_str* mag_query){
}

void copy_mag_data_2_algorithm(mag_input_data_str* mag_query, Mag_inner_data_str mag_data ){
	mag_query->Hx = (double)mag_data.Hx; //TODO: implement this in a more elegant way
	mag_query->Hx = (double)mag_data.Hy;
	mag_query->Hx = (double)mag_data.Hz;
}


/******************************************************/
//magnetometer read data functions
/******************************************************/
void get_acc_data(acc_input_data_str* acc_query){
	Acc_local_data acc_data;
	ADXL345_read_accdata(ACC_ADDR, &acc_data);
	convert_acc_raw_data_2_units(&acc_data);
	copy_acc_data_2_algorithm(acc_query, acc_data);
	update_acc_timer(acc_query);
}

void convert_acc_raw_data_2_units(Acc_local_data* acc_data){
	acc_data->Ax *= ACC_SCALE_FACTOR;
	acc_data->Ay *= ACC_SCALE_FACTOR;
	acc_data->Az *= ACC_SCALE_FACTOR;
}

void copy_acc_data_2_algorithm(acc_input_data_str* acc_query, Acc_local_data acc_data ){
	acc_query->Ax = acc_data.Ax;
	acc_query->Ay = acc_data.Ay;
	acc_query->Az = acc_data.Az;
}

/******************************************************/
//gyroscope read data functions
/******************************************************/

void get_gyr_data(gyr_input_data_str* gyr_query){
	Gyr_local_data gyr_data;
	ITG3200_read_gyrdata(GYR_ADDR, &gyr_data);
	update_gyr_timer(gyr_query);
	convert_gyr_raw_data_2_units(&gyr_data);
	copy_data_2_algorithm(gyr_query, gyr_data);
}

void convert_gyr_raw_data_2_units(Gyr_local_data* gyr_data){
	gyr_data->Wr /= GYR_SCALE_FACTOR;
	gyr_data->Wp /= GYR_SCALE_FACTOR;
	gyr_data->Wy /= GYR_SCALE_FACTOR;
}

void copy_data_2_algorithm(gyr_input_data_str* gyr_query, Gyr_local_data gyr_data){
	gyr_query->Wr = gyr_data.Wr;
	gyr_query->Wp = gyr_data.Wp;
	gyr_query->Wy = gyr_data.Wy;
}


void get_gps_data(gps_input_data_str* gps_input){

}


/******************************************************/
//timer functions
/******************************************************/


void update_acc_timer (acc_input_data_str* acc_query){
	Timer_IF_Stop(TIMERA1_BASE,TIMER_A); //not sure if needed
	acc_query->time = CLOCK_PERIOD_USEC*(Timer_IF_GetCount(TIMERA1_BASE,TIMER_A)); //in uSec
	Timer_IF_Init(PRCM_TIMERA1,TIMERA1_BASE,TIMER_CFG_ONE_SHOT_UP,TIMER_A,0);
	Timer_IF_Start(TIMERA1_BASE,TIMER_A,0);
}

void update_gyr_timer (gyr_input_data_str* gyr_query){
	Timer_IF_Stop(TIMERA2_BASE,TIMER_A); //not sure if needed
	gyr_query->time =  CLOCK_PERIOD_USEC*(Timer_IF_GetCount(TIMERA2_BASE,TIMER_A));
	Timer_IF_Init(PRCM_TIMERA2,TIMERA2_BASE,TIMER_CFG_ONE_SHOT_UP,TIMER_A,0);
	Timer_IF_Start(TIMERA1_BASE,TIMER_A,0);
}