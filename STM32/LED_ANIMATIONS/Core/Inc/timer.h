/*
 * timer.h
 *
 *  Created on: Oct 22, 2024
 *      Author: doqua
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

extern int timer1_counter;
extern int timer2_counter;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void timerRun();


#endif /* INC_TIMER_H_ */
