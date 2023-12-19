/*
 * control_data.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */

#include "control_data.h"

char temp[1] = {'0'};
char buffer[MAX_BUFFER_SIZE];

uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;
uint32_t ADC_Value = 0;
uint32_t ADC_Value_buffer = 0;

void initData() {
	for (uint8_t i = 0; i < MAX_BUFFER_SIZE; i++) {
		buffer[i] = '0';
	}
	index_buffer = 0;
}

void insertBuffer() {
	buffer[index_buffer++] = temp[0];
	if (index_buffer == MAX_BUFFER_SIZE + 1) {
		initData();
		index_buffer = 0;
		return;
	}
	buffer_flag = 1;
}
