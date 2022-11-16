/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2022
 *      Author: PC
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch(status3) {
	case MAN_RED:
		if (timer4_flag == 1) {
			ToggleLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
			ToggleLED(LED_RED2_GPIO_Port, LED_RED2_Pin);
			setTimer4(BLINKY_TIME);
		}

		if (isPressedButton(0)) {
			status3 = MAN_YELLOW;
			ClearAllLED();
			TurnOnLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			TurnOnLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			setTimer4(BLINKY_TIME);
		}

		if (isPressedButton(1)) {
			man_red_time++;
			if (man_red_time >= 100) man_red_time = 0;

			display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
						a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
						man_red_time / 10);

			display7SEG(a2_Pin, b2_Pin, c2_Pin, d2_Pin, e2_Pin, f2_Pin, g2_Pin,
						a2_GPIO_Port, b2_GPIO_Port, c2_GPIO_Port, d2_GPIO_Port, e2_GPIO_Port, f2_GPIO_Port, g2_GPIO_Port,
						man_red_time % 10);

		}

		if (isPressedButton(2)) {
			red_time = man_red_time;
		}

		break;
	case MAN_YELLOW:
		if (timer4_flag == 1) {
			ToggleLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			ToggleLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			setTimer4(BLINKY_TIME);
		}

		if (isPressedButton(0)) {
			status3 = MAN_GREEN;
			ClearAllLED();
			TurnOnLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			TurnOnLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			setTimer4(BLINKY_TIME);
		}

		if (isPressedButton(1)) {
			man_yellow_time++;
			if (man_yellow_time >= 100) man_yellow_time = 0;
		}

		if (isPressedButton(2)) {
			yellow_time = man_yellow_time;
		}

		break;
	case MAN_GREEN:
		if (timer4_flag == 1) {
			ToggleLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			ToggleLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			setTimer4(BLINKY_TIME);
		}

		if (isPressedButton(0)) {
			status1 = INIT;
			status2 = INIT;
			status3 = -1;

			ClearAllLED();
			ClearLEDSEG();
		}

		if (isPressedButton(1)) {
			man_green_time++;
			if (man_green_time >= 100) man_green_time = 0;
		}

		if (isPressedButton(2)) {
			green_time = man_green_time;
		}

		break;
	default:
		break;
	}
}
