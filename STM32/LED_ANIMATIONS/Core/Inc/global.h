/*
 * global.h
 *
 *  Created on: Oct 22, 2024
 *      Author: doqua
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "timer.h"
#include "led_display.h"

#define INIT        1
#define AUTO_RED    2
#define AUTO_GREEN  3
#define AUTO_YELLOW 4

extern int status_1;
extern int status_2;

extern int current_mode;
extern int red_duration;
extern int green_duration;
extern int amber_duration;

#define MODE_1 1
#define MODE_2 2
#define MODE_3 3
#define MODE_4 4

#define BUTTON_1 1
#define BUTTON_2 2
#define BUTTON_3 3

#endif /* INC_GLOBAL_H_ */
