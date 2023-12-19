/*
 * software_timer.c
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */

#include "software_timer.h"

int timer_counter = 0;
int timer_flag = 0;

int timer_blinking;
int timer_blinking_flag;

void setTimer(int duration) {
	timer_counter = duration;
	timer_flag = 0;
}

void setTimerBlinking() {
	timer_blinking = 50;
	timer_blinking_flag = 0;
}

void timerRun() {
	if (timer_counter > 0) {
		timer_counter--;
		if (timer_counter == 0) {
			timer_flag = 1;
		}
	}
	if (timer_blinking > 0) {
		timer_blinking--;
		if (timer_blinking == 0) {
			timer_blinking_flag = 1;
		}
	}
}
