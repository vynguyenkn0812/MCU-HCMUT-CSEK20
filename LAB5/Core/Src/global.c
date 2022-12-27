/*
 * global.c
 *
 *  Created on: Dec 27, 2022
 *      Author: PC
 */

#include "global.h"

uint8_t buffer_rx[MAX_BUFFER_SIZE] = {0};
uint8_t buffer_tx[MAX_BUFFER_SIZE] = {0};
uint8_t command_parser_data[MAX_BUFFER_SIZE] = {0};

int status_parser = 0;
int status_communicate = 0;

uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

uint8_t temp = 0;
uint8_t ADC_value = 0;

int cmd_flag = 0;
