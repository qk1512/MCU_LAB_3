/*
 * led_display.h
 *
 *  Created on: Oct 22, 2024
 *      Author: doqua
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

extern int led_buffer_A[2];
extern int led_buffer_B[2];


void display7SEG(int num);
void display7SEG_B(int num);

void off_led();
void on_led();
void binkly_led();

void update7SEG(int index);
void update7SEG_B(int index);


#endif /* INC_LED_DISPLAY_H_ */