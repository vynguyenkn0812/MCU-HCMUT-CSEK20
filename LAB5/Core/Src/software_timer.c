/*
 * software_timer.c
 *
 *  Created on: Dec 27, 2022
 *      Author: PC
 */

#include "software_timer.h"

int timer1_flag = 0;
int timer2_flag = 0;

int timer1_counter = 0;
int timer2_counter = 0;

void setTimer1(int duration) {

	timer1_counter = duration/TIME_CYCLE;
	timer1_flag = 0;

}

void setTimer2(int duration) {

	timer2_counter = duration/TIME_CYCLE;
	timer2_flag = 0;

}


void clearTimer1() {
	timer1_counter = 0;
	timer1_flag = 0;
}

void clearTimer2() {
	timer2_counter = 0;
	timer2_flag = 0;
}


void timerRun() {

	if (timer1_counter > 0) {

		timer1_counter--;
		if (timer1_counter <= 0) {

			timer1_flag = 1;
		}

	}

	if (timer2_counter > 0) {

		timer2_counter--;
		if (timer2_counter <= 0) {

			timer2_flag = 1;
		}

	}

}
