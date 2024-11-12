/*
 * global.h
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include"main.h"
#include"softwaretimer.h"
#include"port_pin.h"
#include"displaysevensegment.h"
#include"button_reading.h"
#include"ledred.h"
#include"fsm_simple.h"
#include"processing.h"
#define MINIMUM_TWO_DIGITS_NUMBER 10
#define MAXIMUM_TWO_DIGITS_NUMBER 99
#define MAXIMU_VALUE 9
#define MINIMUM_VALUE 0
#define ONE_SECOND 1000
#define HALF_SECOND 500
#define HUNDRED_MILLISECOND 100
#define FIRSTSEVENSEGMENTLED 0
#define INIT 0
#define RESET 1
#define INC 2
#define DEC 3
#define AUTODECREASE 4
#define LONGPRESSINC 11
#define LONGPRESSDEC 12
#define FIRST_BUTTON 0
#define SECOND_BUTTON 1
#define THIRD_BUTTON 2
#define TEN_SECOND 10000
#define DURATION_FOR_AUTO_CHANGE 100
extern int status,counterLed,counterForLongPress,counterForAutoDecrease;
#endif /* INC_GLOBAL_H_ */

