/*
 * display_LED.c
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#include "display_LED.h"

void clearLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_WritePin(Port, Pin, SET);
}

void blinkyLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_TogglePin(Port, Pin);
}

void clear7SEG(uint16_t Pin1, uint16_t Pin2, uint16_t Pin3, uint16_t Pin4, uint16_t Pin5, uint16_t Pin6, uint16_t Pin7,
		 	   GPIO_TypeDef* Port1, GPIO_TypeDef* Port2, GPIO_TypeDef* Port3, GPIO_TypeDef* Port4, GPIO_TypeDef* Port5, GPIO_TypeDef* Port6, GPIO_TypeDef* Port7) {
	HAL_GPIO_WritePin(Port1, Pin1, SET);
	HAL_GPIO_WritePin(Port2, Pin2, SET);
	HAL_GPIO_WritePin(Port3, Pin3, SET);
	HAL_GPIO_WritePin(Port4, Pin4, SET);
	HAL_GPIO_WritePin(Port5, Pin5, SET);
	HAL_GPIO_WritePin(Port6, Pin6, SET);
	HAL_GPIO_WritePin(Port7, Pin7, SET);
}

void display7SEG(uint16_t Pin1, uint16_t Pin2, uint16_t Pin3, uint16_t Pin4, uint16_t Pin5, uint16_t Pin6, uint16_t Pin7,
				 GPIO_TypeDef* Port1, GPIO_TypeDef* Port2, GPIO_TypeDef* Port3, GPIO_TypeDef* Port4, GPIO_TypeDef* Port5, GPIO_TypeDef* Port6, GPIO_TypeDef* Port7,
				 int num) {
	switch(num) {
	case 0: //Number 0 is 0000001
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;

	case 1: //Number 1 is 1001111
		HAL_GPIO_WritePin(Port1, Pin1, SET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;

	case 2: //Number 2 is 0010010
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, SET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 3: //Number 3 is 0000110
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 4: //Number 4 is 1001100
		HAL_GPIO_WritePin(Port1, Pin1, SET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 5: //Number 5 is 0100100
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, SET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 6: //Number 6 is 0100000
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, SET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 7: //Number 7 is 0001111
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;

	case 8: //Number 8 is 0000000
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 9: //Number 9 is 0000100
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	default:
		HAL_GPIO_WritePin(Port1, Pin1, SET);
		HAL_GPIO_WritePin(Port2, Pin2, SET);
		HAL_GPIO_WritePin(Port3, Pin3, SET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;
	}
}
