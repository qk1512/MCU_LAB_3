/*
 * button_reading.h
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */
#ifndef INC_BUTTON_READING_H_
#define INC_BUTTON_READING_H_

#include"global.h"

#define NO_OF_BUTTONS 3
#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET
extern int timeForKeyPress;
void buttonReading();
int isButtonPressed(int index);
int isButtonPressedMoreThan3s(int index);
#endif /* INC_BUTTON_READING_H_ */

