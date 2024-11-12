/*
 * input_processing.c
 *
 *  Created on: Nov 12, 2024
 *      Author: doqua
 */

#include "input_processing.h"

void fsm_for_input_processing() {
    switch(current_mode){
        case MODE_1:  // Normal Mode
            if (is_button_pressed(BUTTON_1)) {
                current_mode = MODE_2;  // Switch to Red duration modification
                display7SEG(9);
            }
            break;
        case MODE_2:  // Modify Red LED Duration
            if (is_button_pressed(BUTTON_2)) {
                red_duration = (red_duration + 1) % 100; // Increase duration
            }
            if (is_button_pressed(BUTTON_3)) {
                current_mode = MODE_3;  // Save value and switch to next mode
            }
            break;
        case MODE_3:  // Modify Amber LED Duration
            if (is_button_pressed(BUTTON_2)) {
                amber_duration = (amber_duration + 1) % 100;
            }
            if (is_button_pressed(BUTTON_3)) {
                current_mode = MODE_4;
            }
            break;
        case MODE_4:  // Modify Green LED Duration
            if (is_button_pressed(BUTTON_2)) {
                green_duration = (green_duration + 1) % 100;
            }
            if (is_button_pressed(BUTTON_3)) {
                current_mode = MODE_1;
            }
            break;
    }
}
