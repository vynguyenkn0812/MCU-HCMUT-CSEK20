/*
 * fsm_automatic.c
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */

#include "fsm_automatic.h"

void fsm_automatic_run1() {
	switch(status1) {
		case INIT:
			status1 = AUTO_RED;
			count_down1 = red_time;
			setTimer1(50);
			setTimer3(50);
			setTimer4(50);

			if (isPressedButton(0)) {
				status1 = -1;
				status3 = MAN_RED;

				count_down1 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			break;
		case AUTO_RED:
			if (timer1_flag == 1) {
				status1 = AUTO_GREEN;

				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOffLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				TurnOffLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);

				count_down1 = red_time;

				setTimer1(red_time * 1000);
			}

			if (isPressedButton(0)) {
				status1 = -1;
				status3 = MAN_RED;

				count_down1 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			displayLEDSEGCountingDown();

			break;
		case AUTO_GREEN:
			if (timer1_flag == 1) {
				status1 = AUTO_YELLOW;

				TurnOnLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
				TurnOffLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOffLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);

				count_down1 = green_time;

				setTimer1(green_time * 1000);
			}

			if (isPressedButton(0)) {
				status1 = -1;
				status3 = MAN_RED;

				count_down1 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			displayLEDSEGCountingDown();

			break;
		case AUTO_YELLOW:
			if (timer1_flag == 1) {
				status1 = AUTO_RED;

				TurnOnLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
				TurnOffLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOffLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);

				count_down1 = yellow_time;

				setTimer1(yellow_time * 1000);
			}

			if (isPressedButton(0)) {
				status1 = -1;
				status3 = MAN_RED;

				count_down1 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			displayLEDSEGCountingDown();

			break;
		default:
			break;
	}

}

void fsm_automatic_run2() {
	switch(status2) {
		case INIT:
			status2 = AUTO_GREEN;
			count_down2 = green_time;
			setTimer2(50);
			setTimer3(50);
			setTimer4(50);

			if (isPressedButton(0)) {
				status2 = -1;
				status3 = MAN_RED;

				count_down2 = -1;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			break;
		case AUTO_RED:
			if (timer2_flag == 1) {
				status2 = AUTO_GREEN;

				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);
				TurnOffLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				TurnOffLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);

				count_down2 = red_time;

				setTimer2(red_time * 1000);
			}

			if (isPressedButton(0)) {
				status2 = -1;
				status3 = MAN_RED;

				count_down2 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			displayLEDSEGCountingDown();

			break;
		case AUTO_GREEN:
			if (timer2_flag == 1) {
				status2 = AUTO_YELLOW;

				TurnOnLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
				TurnOffLED(LED_RED2_GPIO_Port, LED_RED2_Pin);
				TurnOffLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);

				count_down2 = green_time;

				setTimer2(green_time * 1000);
			}

			if (isPressedButton(0)) {
				status2 = -1;
				status3 = MAN_RED;

				count_down2 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			displayLEDSEGCountingDown();

			break;
		case AUTO_YELLOW:
			if (timer2_flag == 1) {
				status2 = AUTO_RED;

				TurnOnLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
				TurnOffLED(LED_RED2_GPIO_Port, LED_RED2_Pin);
				TurnOffLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);

				count_down2 = yellow_time;

				setTimer2(yellow_time * 1000);
			}

			if (isPressedButton(0)) {
				status2 = -1;
				status3 = MAN_RED;

				count_down2 = -1;
				man_red_time = red_time;
				man_yellow_time = yellow_time;
				man_green_time = green_time;

				ClearAllLED();
				ClearLEDSEG();
				TurnOnLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
				TurnOnLED(LED_RED2_GPIO_Port, LED_RED2_Pin);

				HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
				display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
							a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
							1);

				clearTimer1();
				clearTimer2();
				clearTimer3();
				setTimer4(500);
			}

			displayLEDSEGCountingDown();

			break;
		default:
			break;
	}
}
