/*
 * control_data.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */

#ifndef INC_CONTROLDATA_H_
#define INC_CONTROLDATA_H_

#include <stdio.h>

#define MAX_BUFFER_SIZE 20

// temp for a new data
extern char temp[1];

// buffer for input
extern char buffer[MAX_BUFFER_SIZE];

// index_buffer for inserting
extern uint8_t index_buffer;

// buffer_flag for checking a new data
extern uint8_t buffer_flag;

// ADC_Value for uart communication
extern uint32_t ADC_Value;

// ADC_Value_buffer for old value in time out
extern uint32_t ADC_Value_buffer;

// To set initial data to buffer or reset data in buffer
void initData();

// To insert data to buffer
void insertBuffer();

#endif /* INC_CONTROL_DATA_H_ */
