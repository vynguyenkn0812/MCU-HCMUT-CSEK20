/*
 * fsm_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_button.h"

void fsm_simple_button_run() {
	if (timer2_flag == 1) {
		blinkyLED(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer2(1000);
	}

	switch(button_status) {
		case INIT:
			button_status = NORMAL;
			counter = 10;
			setTimer1(100);
			setTimer2(100);

		case NORMAL:
			if (flagForButtonPress[BUTTON_RESET - 11] == 1) {
				button_status = BUTTON_RESET;
				clearTimer1();
			} else if (flagForButtonPress[BUTTON_INC - 11] == 1) {
				button_status = BUTTON_INC;
				clearTimer1();
			} else if (flagForButtonPress[BUTTON_DEC - 11] == 1) {
				button_status = BUTTON_DEC;
				clearTimer1();
			} else {

				if (timer1_flag == 1) {
					if (counter > 0) {
						counter--;
					}

					display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
								LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
								counter);

					setTimer1(1000);
				}
			}
			break;

		case BUTTON_RESET:
			if (isPressedButton(BUTTON_RESET - 11) == 1) {
				counter = 0;
				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);
			}

			if (flagForButtonPress[BUTTON_RESET - 11] == 1) {
				button_status = BUTTON_RESET;
			} else if (flagForButtonPress[BUTTON_INC - 11] == 1) {
				button_status = BUTTON_INC;
			} else if (flagForButtonPress[BUTTON_DEC - 11] == 1) {
				button_status = BUTTON_DEC;
			}

			break;

		case BUTTON_INC:
			if (isPressedButton(BUTTON_INC - 11) == 1) {

				if (counter >= 9) {
					counter = -1;
				}
				counter++;

				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);
			}

			if (flagForButtonPress[BUTTON_RESET - 11] == 1) {
				button_status = BUTTON_RESET;
			} else if (flagForButtonPress[BUTTON_INC - 11] == 1) {
				button_status = BUTTON_INC;
			} else if (flagForButtonPress[BUTTON_DEC - 11] == 1) {
				button_status = BUTTON_DEC;
			}

			break;

		case BUTTON_DEC:
			if (isPressedButton(BUTTON_DEC - 11) == 1) {

				if (counter <= 0) {
					counter = 10;
				}

				counter--;

				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);
			}

			if (flagForButtonPress[BUTTON_RESET - 11] == 1) {
				button_status = BUTTON_RESET;
			} else if (flagForButtonPress[BUTTON_INC - 11] == 1) {
				button_status = BUTTON_INC;
			} else if (flagForButtonPress[BUTTON_DEC - 11] == 1) {
				button_status = BUTTON_DEC;
			}

			break;

		default:
			break;
	}
}
