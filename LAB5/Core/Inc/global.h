/*
 * global.h
 *
 *  Created on: Dec 27, 2022
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

#define MAX_BUFFER_SIZE 30 //MAX UART BUFFER

#define INIT 				0

// status of command parser
#define WAIT_TOKEN 			1
#define RECEIVE_DATA		2

// status of UART
#define WAIT_COMMAND_RST 	11
#define SEND_DATA			12

extern uint8_t buffer_rx[MAX_BUFFER_SIZE];
extern uint8_t buffer_tx[MAX_BUFFER_SIZE];
extern uint8_t command_parser_data[MAX_BUFFER_SIZE];

extern int status_parser;
extern int status_communicate;

extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t temp;
extern uint8_t ADC_value;

extern int cmd_flag;


#endif /* INC_GLOBAL_H_ */
