/*
 * display_LED.c
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */

#include "display_LED.h"

void TurnOnLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_WritePin(Port, Pin, SET);
}

void TurnOffLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_WritePin(Port, Pin, RESET);
}

void ToggleLED(GPIO_TypeDef* Port, uint16_t Pin) {
	HAL_GPIO_TogglePin(Port, Pin);
}

void ClearAllLED() {
	TurnOffLED(LED_RED1_GPIO_Port, LED_RED1_Pin);
	TurnOffLED(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
	TurnOffLED(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);

	TurnOffLED(LED_RED2_GPIO_Port, LED_RED2_Pin);
	TurnOffLED(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin);
	TurnOffLED(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin);
}

void ClearLEDSEG() {
	//disable LEG7SEG
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

	HAL_GPIO_WritePin(a1_GPIO_Port, a1_Pin, SET);
	HAL_GPIO_WritePin(b1_GPIO_Port, b1_Pin, SET);
	HAL_GPIO_WritePin(c1_GPIO_Port, c1_Pin, SET);
	HAL_GPIO_WritePin(d1_GPIO_Port, d1_Pin, SET);
	HAL_GPIO_WritePin(e1_GPIO_Port, e1_Pin, SET);
	HAL_GPIO_WritePin(f1_GPIO_Port, f1_Pin, SET);
	HAL_GPIO_WritePin(g1_GPIO_Port, g1_Pin, SET);

	HAL_GPIO_WritePin(a2_GPIO_Port, a2_Pin, SET);
	HAL_GPIO_WritePin(b2_GPIO_Port, b2_Pin, SET);
	HAL_GPIO_WritePin(c2_GPIO_Port, c2_Pin, SET);
	HAL_GPIO_WritePin(d2_GPIO_Port, d2_Pin, SET);
	HAL_GPIO_WritePin(e2_GPIO_Port, e2_Pin, SET);
	HAL_GPIO_WritePin(f2_GPIO_Port, f2_Pin, SET);
	HAL_GPIO_WritePin(g2_GPIO_Port, g2_Pin, SET);
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

void displayLEDSEGCountingDown() {
	if (timer3_flag == 1) {
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);

		display7SEG(a1_Pin, b1_Pin, c1_Pin, d1_Pin, e1_Pin, f1_Pin, g1_Pin,
					a1_GPIO_Port, b1_GPIO_Port, c1_GPIO_Port, d1_GPIO_Port, e1_GPIO_Port, f1_GPIO_Port, g1_GPIO_Port,
					count_down1--);

		display7SEG(a2_Pin, b2_Pin, c2_Pin, d2_Pin, e2_Pin, f2_Pin, g2_Pin,
					a2_GPIO_Port, b2_GPIO_Port, c2_GPIO_Port, d2_GPIO_Port, e2_GPIO_Port, f2_GPIO_Port, g2_GPIO_Port,
					count_down2--);

		setTimer3(1000);
	}
}

