/*
 * ledred.c
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#include"ledred.h"
static int counterRed=0;
int timeForChangeLed=ONE_SECOND/TIME_CYCLE; //100
void ledRedProcessing(){
	counterRed++;
	if(counterRed>timeForChangeLed){
		counterRed=0;
		toggleLedRed();
	}
}
void toggleLedRed(){
	HAL_GPIO_TogglePin(RED_PORT, RED_PIN);
}
