/*
 * software_timer.h
 *
 *  Created on: Dec 18, 2023
 *      Author: Hieu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

// Timer for uart communication
extern int timer_counter;
extern int timer_flag;

// Timer for blinking led
extern int timer_blinking;
extern int timer_blinking_flag;

void setTimer(int duraion);
void setTimerBlinking();
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
