/*
 * softwaretimer.c
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#include"softwaretimer.h"
uint16_t timer1_counter=0;
uint16_t timer2_counter=0;
uint16_t timer3_counter=0;
int timer1_flag=0;
int timer2_flag=0;
int timer3_flag=0;
//timer1 is used for
void setTimer1(uint16_t duration){
	timer1_counter=(duration/TIME_CYCLE)+2;
	timer1_flag=0;
}
//timer2 is used for
void setTimer2(uint16_t duration){
	timer2_counter=(duration/TIME_CYCLE);
	timer2_flag=0;
}
//timer3 is used for first button
void setTimer3(uint16_t duration){
	timer3_counter=(duration/TIME_CYCLE);
	timer3_flag=0;
}
//timer4 is used for second button
void timerRun(){
	if(timer1_counter>0){
		timer1_counter--;
		if(timer1_counter==0){
			timer1_flag=1;
		}
	}
	if(timer2_counter>0){
		timer2_counter--;
		if(timer2_counter==0){
			timer2_flag=1;
		}
	}
	if(timer3_counter>0){
		timer3_counter--;
		if(timer3_counter==0){
			timer3_flag=1;
		}
	}
}
