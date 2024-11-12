/*
 * led_display.c
 *
 *  Created on: Oct 22, 2024
 *      Author: doqua
 */

#include "led_display.h"
#include "fsm_automatic.h"
#include "timer.h"

int led_buffer_A[2] = {0,2};
int led_buffer_B[2] = {0,4};


const uint8_t segmentPatterns[10] = {
    0b00111111, // 0: ABCDEF_
    0b00000110, // 1: __BC____
    0b01011011, // 2: AB_DEG__
    0b01001111, // 3: ABCD__G_
    0b01100110, // 4: _BC__FG_
    0b01101101, // 5: AB__D_F_
    0b01111101, // 6: ABCD_F__
    0b00000111, // 7: __BC____
    0b01111111, // 8: ABCDEFG_
    0b01101111  // 9: ABCD__G_
};


void display7SEG(int num) {
    if (num < 0 || num > 9) return; // Handle invalid input

    uint8_t pattern = segmentPatterns[num];

    HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (pattern & 0x01) ? 0 : 1);
    HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (pattern & 0x02) ? 0 : 1);
    HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (pattern & 0x04) ? 0 : 1);
    HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (pattern & 0x08) ? 0 : 1);
    HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (pattern & 0x10) ? 0 : 1);
    HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (pattern & 0x20) ? 0 : 1);
    HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (pattern & 0x40) ? 0 : 1);
}


void display7SEG_B(int num) {
    if (num < 0 || num > 9) return; // Handle invalid input

    uint8_t pattern = segmentPatterns[num];

    HAL_GPIO_WritePin(SEG_0B_GPIO_Port, SEG_0B_Pin, (pattern & 0x01) ? 0 : 1);
    HAL_GPIO_WritePin(SEG_1B_GPIO_Port, SEG_1B_Pin, (pattern & 0x02) ? 0 : 1);
    HAL_GPIO_WritePin(SEG_2B_GPIO_Port, SEG_2B_Pin, (pattern & 0x04) ? 0 : 1);
    HAL_GPIO_WritePin(SEG_3B_GPIO_Port, SEG_3B_Pin, (pattern & 0x08) ? 0 : 1);
    HAL_GPIO_WritePin(SEG_4B_GPIO_Port, SEG_4B_Pin, (pattern & 0x10) ? 0 : 1);
    HAL_GPIO_WritePin(SEG_5B_GPIO_Port, SEG_5B_Pin, (pattern & 0x20) ? 0 : 1);
    HAL_GPIO_WritePin(SEG_6B_GPIO_Port, SEG_6B_Pin, (pattern & 0x40) ? 0 : 1);
}


void off_led(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port,GREEN_1_Pin,0);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port,YELLOW_1_Pin,0);
	HAL_GPIO_WritePin(RED_1_GPIO_Port,RED_1_Pin,0);

	HAL_GPIO_WritePin(GREEN_2_GPIO_Port,GREEN_2_Pin,0);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port,YELLOW_2_Pin,0);
	HAL_GPIO_WritePin(RED_2_GPIO_Port,RED_2_Pin,0);
}

void on_led(){
	HAL_GPIO_WritePin(GREEN_1_GPIO_Port,GREEN_1_Pin,1);
	HAL_GPIO_WritePin(YELLOW_1_GPIO_Port,YELLOW_1_Pin,1);
	HAL_GPIO_WritePin(RED_1_GPIO_Port,RED_1_Pin,1);

	HAL_GPIO_WritePin(GREEN_2_GPIO_Port,GREEN_2_Pin,1);
	HAL_GPIO_WritePin(YELLOW_2_GPIO_Port,YELLOW_2_Pin,1);
	HAL_GPIO_WritePin(RED_2_GPIO_Port,RED_2_Pin,1);
}

void binkly_led(){
	HAL_GPIO_TogglePin(GREEN_1_GPIO_Port, GREEN_1_Pin);
	HAL_GPIO_TogglePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin);
	HAL_GPIO_TogglePin(RED_1_GPIO_Port, RED_1_Pin);

	HAL_GPIO_TogglePin(GREEN_2_GPIO_Port, GREEN_2_Pin);
	HAL_GPIO_TogglePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin);
	HAL_GPIO_TogglePin(RED_2_GPIO_Port, RED_2_Pin);
}

void update7SEG(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port,EN0_Pin,0);
		HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin,1);
		display7SEG(led_buffer_A[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port,EN0_Pin,1);
		HAL_GPIO_WritePin(EN1_GPIO_Port,EN1_Pin,0);
		display7SEG(led_buffer_A[1]);
		break;
	}
}


void update7SEG_B(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin,0);
		HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin,1);
		display7SEG_B(led_buffer_B[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN2_GPIO_Port,EN2_Pin,1);
		HAL_GPIO_WritePin(EN3_GPIO_Port,EN3_Pin,0);
		display7SEG_B(led_buffer_B[1]);
		break;
	}
}
