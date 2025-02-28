/*
 * fsm_automatic.c
 *
 *  Created on: Oct 22, 2024
 *      Author: doqua
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status_1){
	case INIT:
		off_led();
		status_1 = AUTO_RED;
		setTimer1(red_duration);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(RED_1_GPIO_Port,RED_1_Pin,1);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port,YELLOW_1_Pin,0);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port,GREEN_1_Pin,0);

		if(timer1_flag == 1){
			status_1 = AUTO_GREEN;
			setTimer1(green_duration);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(RED_1_GPIO_Port,RED_1_Pin,0);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port,YELLOW_1_Pin,0);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port,GREEN_1_Pin,1);

		if(timer1_flag == 1){
			status_1 = AUTO_YELLOW;
			setTimer1(amber_duration);
		}
		break;
	case AUTO_YELLOW:
		HAL_GPIO_WritePin(RED_1_GPIO_Port,RED_1_Pin,0);
		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port,YELLOW_1_Pin,1);
		HAL_GPIO_WritePin(GREEN_1_GPIO_Port,GREEN_1_Pin,0);
		if(timer1_flag == 1){
			status_1 = AUTO_RED;
			setTimer1(red_duration);
		}
		break;
	default:
		break;
	}

	switch(status_2){
		case INIT:
			off_led();
			status_2 = AUTO_GREEN;
			setTimer2(300);
			break;
		case AUTO_RED:
			HAL_GPIO_WritePin(RED_2_GPIO_Port,RED_2_Pin,1);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port,YELLOW_2_Pin,0);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port,GREEN_2_Pin,0);

			if(timer2_flag == 1){
				status_2 = AUTO_GREEN;
				setTimer2(300);
			}
			break;
		case AUTO_GREEN:
			HAL_GPIO_WritePin(RED_2_GPIO_Port,RED_2_Pin,0);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port,YELLOW_2_Pin,0);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port,GREEN_2_Pin,1);

			if(timer2_flag == 1){
				status_2 = AUTO_YELLOW;
				setTimer2(200);
			}
			break;
		case AUTO_YELLOW:
			HAL_GPIO_WritePin(RED_2_GPIO_Port,RED_2_Pin,0);
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port,YELLOW_2_Pin,1);
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port,GREEN_2_Pin,0);

			if(timer2_flag == 1){
				status_2 = AUTO_RED;
				setTimer2(500);
			}
			break;
		default:
			break;
		}
}
