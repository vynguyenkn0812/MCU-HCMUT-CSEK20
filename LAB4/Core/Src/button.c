/*
 * button.c
 *
 *  Created on: Dec 7, 2022
 *      Author: PC
 */

#include "button.h"

GPIO_PinState debounceButtonBuffer0[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED};
GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED};
GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED};

GPIO_PinState buttonBuffer[NO_OF_BUTTONS] = {BUTTON_IS_RELEASED};

int flagForButtonPress[NO_OF_BUTTONS] = {0};
int flagForButtonLongPress[NO_OF_BUTTONS] = {0};

int counterForButtonLongPress[NO_OF_BUTTONS] = {DURATION_FOR_AUTO_INCREASING};

GPIO_PinState KeyInput(int index) {
	switch (index) {
		case 0:
			return HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
		//....

		default:
			return BUTTON_IS_RELEASED;
	}
	return BUTTON_IS_RELEASED;
}

void subKeyProcess(int index) {

	flagForButtonPress[index] = 1;
}

void subKeyLongProcess(int index) {

	flagForButtonLongPress[index] = 1;

}

int isPressedButton(int index) {
	if (index >= NO_OF_BUTTONS) {
		return -1;
	}

	else if (flagForButtonPress[index] == 1) {
		flagForButtonPress[index] = 0;
		return 1;
	}

	return 0;
}

int isLongPressButton(int index) {
	if (index >= NO_OF_BUTTONS) {
		return -1;
	}

	else if (flagForButtonLongPress[index] == 1) {
		flagForButtonLongPress[index] = 0;
		return 1;
	}

	return 0;
}

void getKeyInput() {
	for (int i = 0; i < NO_OF_BUTTONS; ++i) {
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = debounceButtonBuffer0[i];
		debounceButtonBuffer0[i] = KeyInput(i);

		if ((debounceButtonBuffer1[i] == debounceButtonBuffer0[i]) &&
			(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])) {
			if (debounceButtonBuffer2[i] != buttonBuffer[i]) {
				buttonBuffer[i] = debounceButtonBuffer2[i];
				isLongPressButton(i); //off long-pressed flag

				if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
					counterForButtonLongPress[i] = DURATION_FOR_AUTO_INCREASING;
					subKeyProcess(i); //set pressed flag
				}
			} else {
				counterForButtonLongPress[i]--;
				if (counterForButtonLongPress[i] <= 0) {
					if (debounceButtonBuffer2[i] == BUTTON_IS_PRESSED) {
						isPressedButton(i); //off pressed flag
						subKeyLongProcess(i); //set long-pressed flag
					}
					counterForButtonLongPress[i] = DURATION_FOR_AUTO_INCREASING;
				}
			}
		}
	}
}

