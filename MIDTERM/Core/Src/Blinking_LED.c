/*
 * Blinking_LED.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "Blinking_LED.h"


void Blinking_LED() {
	if (timer2_flag == 1) {
		blinkyLED(LED_RED_GPIO_Port, LED_RED_Pin);
		setTimer2(1000);
	}
}
