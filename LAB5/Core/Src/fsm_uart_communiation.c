/*
 * fsm_uart_communiation.c
 *
 *  Created on: Dec 27, 2022
 *      Author: PC
 */

#include "fsm_uart_communiation.h"

int check_receive_RST() {
	if (command_parser_data[0] == 'R' && command_parser_data[1] == 'S' && command_parser_data[2] == 'T') {
		return 1;
	}
	return 0;
}

int check_receive_OK() {
	if (command_parser_data[0] == 'O' && command_parser_data[1] == 'K') {
		return 1;
	}
	return 0;
}

void fsm_uart_communiation(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch(status_communicate) {
	case INIT:
		status_communicate = WAIT_COMMAND_RST;
		break;
	case WAIT_COMMAND_RST:
		if (cmd_flag == 1) {
			cmd_flag = 0;
			if (check_receive_RST() == 1) {
				status_communicate = SEND_DATA;
				setTimer1(3000);
				ADC_value = HAL_ADC_GetValue(&hadc1);
			}
		}
		break;
	case SEND_DATA:
		if (timer1_flag == 1) {
			status_communicate = WAIT_COMMAND_RST;
		}
		HAL_UART_Transmit(&huart2, (void *)buffer_tx, sprintf(buffer_tx, "!ADC=%.4d#", ADC_value), 1000);
		if (cmd_flag == 1) {
			cmd_flag = 0;
			if (check_receive_OK() == 1) {
				status_communicate = WAIT_COMMAND_RST;
			}
		}
		break;
	default:
		break;
	}
}
