/*
 * uart.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */

#include "main.h"
#include "control_data.h"

// To send data
char startData[] = "!ADC";
char endData[] = "#";

// For new line transmit uart activity
uint8_t nl = 0x0D;

// Buffer to get ADC value
char str[20];

void getNewValue() {
	HAL_ADC_Start(&hadc1);
	ADC_Value = HAL_ADC_GetValue(&hadc1);
}

void transfer(uint32_t value) {
	HAL_UART_Transmit(&huart2, startData, 4, 1000);
	HAL_UART_Transmit(&huart2, (void *)str, sprintf(str, "%d\n", value), 1000);
	HAL_UART_Transmit(&huart2, endData, 1, 1000);
	HAL_UART_Transmit(&huart2, &nl, 1, 100);
	HAL_UART_Transmit(&huart2, &nl, 1, 100);
}

void INIT() {
	HAL_ADC_Start(&hadc1);
	ADC_Value = HAL_ADC_GetValue(&hadc1);
	ADC_Value_buffer = ADC_Value;
}
