/*
 * fsm_button_automatic.c
 *
 *  Created on: Nov 6, 2022
 *      Author: PC
 */

#include "fsm_button_automatic.h"

void fsm_automatic_run() {
	switch(button_status) {
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
		default:
			break;
	}
}
