/*
 * display_LED.c
 *
 *  Created on: Dec 4, 2022
 *      Author: PC
 */

#include "display_LED.h"

void ToggleRed() {
	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
}

void ToggleOrange() {
	HAL_GPIO_TogglePin(LED_ORANGE_GPIO_Port, LED_ORANGE_Pin);
}


void ToggleYellow() {
	HAL_GPIO_TogglePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin);
}

void ToggleGreen() {
	HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin);
}

void ToggleOne_shot() {
	HAL_GPIO_TogglePin(ONE_SHOT_LED_GPIO_Port, ONE_SHOT_LED_Pin);
}

void ToggleWhenButtonPressed() {
	if (isPressedButton(0)){
		HAL_GPIO_TogglePin(LED_Pressed_GPIO_Port, LED_Pressed_Pin);
	}
}
