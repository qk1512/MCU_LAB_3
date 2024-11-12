/*
 * softwaretimer.h
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

#include"main.h"
#include"global.h"
#define TIME_CYCLE 10
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
void setTimer1(uint16_t duration);
void setTimer2(uint16_t duration);
void setTimer3(uint16_t duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
