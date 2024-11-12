/*
 * displaysevensegment.h
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#ifndef INC_DISPLAYSEVENSEGMENT_H_
#define INC_DISPLAYSEVENSEGMENT_H_

#include"main.h"
#include"global.h"
#define NUMBER_OF_SEVEN_SEG_LED 1
#define NUMBER_OF_SEGMENTS 7
#define TIME_TO_CHANGE_SEVEN_LED 1000
//function
void updateLedBuffer(uint8_t);
void display7SEG(uint8_t);
void update7SEG(uint8_t );
void turnOffSevenSegment();

#endif /* INC_DISPLAYSEVENSEGMENT_H_ */
