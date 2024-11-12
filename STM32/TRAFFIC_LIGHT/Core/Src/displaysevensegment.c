/*
 * displaysevensegment.c
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#include"displaysevensegment.h"
enum sevenSegOn{First,Second,Third,Fourth};
uint8_t led_buffer [NUMBER_OF_SEVEN_SEG_LED];
uint8_t sevenSegmentCode[10]={0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
GPIO_TypeDef* sevenDataPort[NUMBER_OF_SEGMENTS]={PORT_A, PORT_B, PORT_C, PORT_D, PORT_E, PORT_F, PORT_G};
uint16_t sevenDataPin[NUMBER_OF_SEGMENTS]={PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
void update7SEG(uint8_t index_led){
	display7SEG(sevenSegmentCode[led_buffer[index_led]]);
}
void display7SEG(uint8_t number){
	for(uint8_t segmentIndex=0; segmentIndex< NUMBER_OF_SEGMENTS; segmentIndex++){
		HAL_GPIO_WritePin(sevenDataPort[segmentIndex], sevenDataPin[segmentIndex],
				(GPIO_PinState)(number>>segmentIndex)&(0x01));
	}
}
void updateLedBuffer(uint8_t number){
	led_buffer[0]=number%MINIMUM_TWO_DIGITS_NUMBER;
}
void turnOffSevenSegment(){
	HAL_GPIO_WritePin(PORT_A, PIN_A, SET);
	HAL_GPIO_WritePin(PORT_B, PIN_B, SET);
	HAL_GPIO_WritePin(PORT_C, PIN_C, SET);
	HAL_GPIO_WritePin(PORT_D, PIN_D, SET);
	HAL_GPIO_WritePin(PORT_E, PIN_E, SET);
	HAL_GPIO_WritePin(PORT_F, PIN_F, SET);
	HAL_GPIO_WritePin(PORT_G, PIN_G, SET);
}

