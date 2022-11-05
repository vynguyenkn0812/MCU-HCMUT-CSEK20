/*
 * fsm_button_longpressed.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_button_longpressed.h"


void fsm_longpress_buttons_run() {
	switch(button_status) {
		case BUTTON_INC_LONG_PRESSED:
			if (flagForButtonLongPress[1] == 1) {
				if (timer1_flag == 1) {
					counter++;
					if (counter > 9) {
						counter = 0;
					}

					display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
								LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
								counter);
					setTimer1(1000);
				}

				//if button is pressed -> reset the timer out timer
				clearTimer3();
				setTimer3(10000);

			}

			break;
		case BUTTON_DEC_LONG_PRESSED:
			if (flagForButtonLongPress[2] == 1) {
				if (timer1_flag == 1) {
					if (counter <= 0) {
						counter = 10;
					}

					counter--;

					display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
								LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
								counter);
					setTimer1(1000);
				}

				//if button is pressed -> reset the timer out timer
				clearTimer3();
				setTimer3(10000);

			}

			break;

		default:
			break;
	}
}
