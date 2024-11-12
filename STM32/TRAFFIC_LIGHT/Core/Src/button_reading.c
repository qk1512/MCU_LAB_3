/*
 * button_reading.c
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#include"button_reading.h"
#define DURATION_FOR_AUTO_INCREASING 300
#define AUTO_INCREASING 100
static GPIO_PinState debouncebuttonBuffer0[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState debouncebuttonBuffer1[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState debouncebuttonBuffer2[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState debouncebuttonBuffer3[NO_OF_BUTTONS]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
GPIO_TypeDef* buttonPort[NO_OF_BUTTONS]={BUTTON1_PORT,BUTTON2_PORT,BUTTON3_PORT};
uint16_t buttonPin[NO_OF_BUTTONS]={BUTTON1_PIN,BUTTON2_PIN, BUTTON3_PIN};
static uint8_t flagForButtonPress[NO_OF_BUTTONS]={0,0};
static uint8_t flagForButtonPress3s[NO_OF_BUTTONS]={0,0};
int timeForKeyPress=300;
void buttonReading(){
	for(int i=0;i<NO_OF_BUTTONS;i++){
		debouncebuttonBuffer0[i]=debouncebuttonBuffer1[i];
		debouncebuttonBuffer1[i]=debouncebuttonBuffer2[i];
		debouncebuttonBuffer2[i]=HAL_GPIO_ReadPin(buttonPort[i], buttonPin[i]);
		if((debouncebuttonBuffer0[i]==debouncebuttonBuffer1[i])&&(debouncebuttonBuffer1[i]==debouncebuttonBuffer2[i])){
			if(debouncebuttonBuffer3[i]!=debouncebuttonBuffer2[i]){
				debouncebuttonBuffer3[i]=debouncebuttonBuffer2[i];
				if(debouncebuttonBuffer2[i]==BUTTON_IS_PRESSED){
					flagForButtonPress[i]=1;
					timeForKeyPress=300;
				}
			}
			else{
				timeForKeyPress--;
				if(timeForKeyPress==0){
					if(debouncebuttonBuffer2[i]==BUTTON_IS_PRESSED){
						flagForButtonPress3s[i]=1;
					}
					timeForKeyPress=100;
				}
			}

		}
	}
}
int isButtonPressed(int index){
	if(index>NO_OF_BUTTONS) return 0;
	if(flagForButtonPress[index]==1){
		flagForButtonPress[index]=0;
		return 1;
	}
	return 0;
}
int isButtonPressedMoreThan3s(int index){
	if(index>NO_OF_BUTTONS) return 0;
	if(flagForButtonPress3s[index]==1){
		flagForButtonPress3s[index]=0;
		return 1;
	}
	return 0;
}

