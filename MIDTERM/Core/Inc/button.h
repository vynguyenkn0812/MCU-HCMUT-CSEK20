/*
 * button.h
 *
 *  Created on: Nov 5, 2022
 *      Author: PC
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"

#define NO_OF_BUTTONS					3

#define DURATION_FOR_AUTO_INCREASING	300
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET
#define BUTTON_IS_PRESSED 				GPIO_PIN_RESET

extern int flagForButtonPress[NO_OF_BUTTONS];
extern int flagForButtonLongPress[NO_OF_BUTTONS];

int isPressedButton(int index);
int isLongPressButton(int index);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
