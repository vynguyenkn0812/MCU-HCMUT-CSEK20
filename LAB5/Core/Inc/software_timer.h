/*
 * software_timer.h
 *
 *  Created on: Dec 27, 2022
 *      Author: PC
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIME_CYCLE 10

extern int timer1_flag;
extern int timer2_flag;

void setTimer1(int duration);
void setTimer2(int duration);

void clearTimer1();
void clearTimer2();

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
