/*
 * command_parser.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */

#include "control_data.h"
#include "command_parser.h"
#include "software_timer.h"
#include "fsm.h"
#include <stdio.h>

int command_mode = 0;
int rst_flag = 0;
int ok_flag = 0;

// !RST# = 5 chars
void checkRST() {
	uint8_t index = 19;
	while (index > 0 && buffer[index] == '0') {
		index--;
	}
	if (index < 5) {
		rst_flag = 0;
	}
	if (buffer[index-5] == '!' && buffer[index-4] == 'R' && buffer[index-3] == 'S' && buffer[index-2] == 'T' && buffer[index-1] == '#') {
		rst_flag = 1;
	}
}

// !OK# = 4 chars
void checkOK() {
	uint8_t index = 19;
	while (index > 0 && buffer[index] == '0') {
		index--;
	}
	if (index < 4) {
		ok_flag = 0;
	}
	if (buffer[index-4] == '!' && buffer[index-3] == 'O' && buffer[index-2] == 'K' && buffer[index-1] == '#') {
		ok_flag = 1;
	}
}

void command_parser() {
	switch (command_mode) {
	case 0:
		checkRST();
		if (rst_flag == 1) {
			setTimer(300);
			rst_flag = 0;
			command_mode = 1;
		}
		break;
	case 1:
		checkOK();
		if (ok_flag == 1) {
			setTimer(0);
			command_mode = 2;
			ok_flag = 0;
			communiation_mode = 1;
		}
		break;
	default:
		break;
	}
}
