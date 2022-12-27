/*
 * fsm_command_parser.c
 *
 *  Created on: Dec 27, 2022
 *      Author: PC
 */

#include "fsm_command_parser.h"

int current_index = 0;

void fsm_command_parser(ADC_HandleTypeDef hadc1, UART_HandleTypeDef huart2) {
	switch(status_parser) {
		case INIT:
			status_parser = WAIT_TOKEN;
			break;
		case WAIT_TOKEN:
			if (temp == '!') {
				status_parser = RECEIVE_DATA;
				current_index = 0;
			}
			break;
		case RECEIVE_DATA:
			if (temp != '#') {
				command_parser_data[current_index++] = temp;
			}

			if (temp == '#') {
				status_parser = WAIT_TOKEN;
				cmd_flag = 1;
			}
			break;
		default:
			break;
	}
}
