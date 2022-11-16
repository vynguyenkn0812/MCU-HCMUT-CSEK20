/*
 * display_LED.h
 *
 *  Created on: Nov 3, 2022
 *      Author: PC
 */

#ifndef INC_DISPLAY_LED_H_
#define INC_DISPLAY_LED_H_

#include "main.h"
#include "software_timer.h"
#include "global.h"

void TurnOnLED(GPIO_TypeDef* Port, uint16_t Pin);
void TurnOffLED(GPIO_TypeDef* Port, uint16_t Pin);
void ToggleLED(GPIO_TypeDef* Port, uint16_t Pin);
void ClearAllLED();
void ClearLEDSEG();

void displayLEDSEGCountingDown();
void display7SEG(uint16_t Pin1, uint16_t Pin2, uint16_t Pin3, uint16_t Pin4, uint16_t Pin5, uint16_t Pin6, uint16_t Pin7,
				 GPIO_TypeDef* Port1, GPIO_TypeDef* Port2, GPIO_TypeDef* Port3, GPIO_TypeDef* Port4, GPIO_TypeDef* Port5, GPIO_TypeDef* Port6, GPIO_TypeDef* Port7,
				 int num);

#endif /* INC_DISPLAY_LED_H_ */
