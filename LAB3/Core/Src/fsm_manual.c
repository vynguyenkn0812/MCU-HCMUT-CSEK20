/*
 * fsm_manual.c
 *
 *  Created on: Nov 15, 2022
 *      Author: PC
 */

#include "fsm_manual.h"

void fsm_manual_run() {
	switch(status3) {
	case INIT:
		status1 = INIT;
		status2 = INIT;
	case MAN_RED:
		if (timer4_flag == 1) {
			ToggleLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
			ToggleLED(LED_RED2_GPIO_Port, LED_RED2_Pin);
			setTimer4(500);
		}

		if (isPressedButton(0)) {
			status3 = MAN_YELLOW;
			ClearAllLED();
			TurnOnLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			TurnOnLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			setTimer4(500);
		}

		if (isPressedButton(1)) {
			man_red_time++;
			if (man_red_time >= 100) man_red_time = 0;
		}

		if (isPressedButton(2)) {
			red_time = man_red_time;
		}

		break;
	case MAN_YELLOW:
		if (timer4_flag == 1) {
			ToggleLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			ToggleLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
			setTimer4(500);
		}

		if (isPressedButton(0)) {
			status3 = MAN_GREEN;
			ClearAllLED();
			TurnOnLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			TurnOnLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
			setTimer4(500);
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
			setTimer4(500);
		}

		if (isPressedButton(0)) {
			status3 = INIT;
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
