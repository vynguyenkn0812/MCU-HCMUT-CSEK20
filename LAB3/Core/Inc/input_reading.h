/*
 * button.h
 *
 *  Created on: Nov 1, 2022
 *      Author: PC
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include "global.h"


#define NO_OF_BUTTONS					3

#define DURATION_FOR_AUTO_INCREASING	100 //time out for long press is 3 second
#define BUTTON_IS_RELEASED 				GPIO_PIN_SET
#define BUTTON_IS_PRESSED 				GPIO_PIN_RESET

extern int flagForButtonPress[NO_OF_BUTTONS];
extern int flagForButtonLongPress[NO_OF_BUTTONS];

int isPressedButton(int index);
int isLongPressButton(int index);

void getKeyInput();


#endif /* INC_INPUT_READING_H_ */
