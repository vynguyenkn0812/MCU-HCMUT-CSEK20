/*
 * fsm_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "fsm_button.h"


void fsm_simple_button_run() {
	switch(button_status) {
		case INIT:
			display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
						LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
						counter);
			//call Timer to change timer_flag to 1
			setTimer1(50); //This timer is used for count time to change counter when button is long-pressed
			setTimer2(50); //This timer is used for auto count down (NORMAL) state
			setTimer3(50); //This timer is used for time out to NORMAL state
			setTimer4(50); //This timer is used for blinking led to Debugging

		case NORMAL:
			if (timer2_flag == 1) {
				if (counter > 0) {
					counter--;
				}

				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);

				setTimer2(1000);
			}

			break;

		case BUTTON_RESET: //button RESET is pressed
			if (isPressedButton(0) == 1) {
				counter = 0;
				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);

				//if button is pressed -> reset the timer out timer
				clearTimer3();
				setTimer3(10000);

			}

			break;

		case BUTTON_INC: //button INC is pressed
			if (isPressedButton(1) == 1) {
				counter++;

				if (counter > 9) {
					counter = 0; //counter is 0 - 9, so if counter > 9, it will be 0
				}

				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);

				//if button is pressed -> reset the timer out timer
				clearTimer3();
				setTimer3(10000);

			}

			break;

		case BUTTON_DEC: //button DEC is pressed
			if (isPressedButton(2) == 1) {
				counter--;
				if (counter < 0) {
					counter = 9; //counter is 0 - 9, so if counter < 0, it will be 9
				}

				display7SEG(LED7_0_Pin, LED7_1_Pin, LED7_2_Pin, LED7_3_Pin, LED7_4_Pin, LED7_5_Pin, LED7_6_Pin,
							LED7_0_GPIO_Port, LED7_1_GPIO_Port, LED7_2_GPIO_Port, LED7_3_GPIO_Port, LED7_4_GPIO_Port, LED7_5_GPIO_Port, LED7_6_GPIO_Port,
							counter);

				//if button is pressed -> reset the timer out timer
				clearTimer3();
				setTimer3(10000);

			}

			break;

		default:
			break;
	}

	//Change the button_status if flag of button is 1
	if (flagForButtonPress[0] == 1) {
		button_status = BUTTON_RESET;
	} else if (flagForButtonPress[1] == 1) {
		button_status = BUTTON_INC;
	} else if (flagForButtonPress[2] == 1) {
		button_status = BUTTON_DEC;
	} else if (flagForButtonLongPress[1] == 1) {
		button_status = BUTTON_INC_LONG_PRESSED;
	} else if (flagForButtonLongPress[2] == 1) {
		button_status = BUTTON_DEC_LONG_PRESSED;
	} else { //if don't press any button in 10s, button_status is auto count down (NORMAL)
		if (timer3_flag == 1) {
			button_status = NORMAL;
			clearTimer3();
		}
	}
}
