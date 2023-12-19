/*
 * fsm.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */


#include "main.h"
#include "software_timer.h"
#include "fsm.h"
#include "command.h"
#include "controlData.h"
#include "uart.h"

int communiation_mode = 0;

void uart_communication_fsm() {
	switch (communiation_mode) {
	case 0:
		if (timer_flag == 1){
			setTimer(0);
			command_mode = 2;
			transfer(ADC_Value_buffer);
			command_mode = 0;
			setTimer(0);
		}
		break;
	case 1:
		getNewValue();
		transfer(ADC_Value);
		// Set status environment
		ADC_Value_buffer = ADC_Value;
		communiation_mode = 0;
		command_mode = 0;
		setTimer(0);
		break;
	default:
		break;
	}
}
