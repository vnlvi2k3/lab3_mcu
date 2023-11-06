/*
 * fsm_manual.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Lan Vi
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		if(isButtonPressed(0)){
			status = MAN_AMBER;
			modify_val = amber_timer;
			updateBuffer(2);
		}
		if(isButtonPressed(1)){
			if((modify_val <= 1) || (modify_val >= 99)){
				modify_val = 2;
			}
			else modify_val ++;
			updateBuffer(1);
		}
		if(isButtonPressed(2)){
			red_timer = modify_val;
			if(red_timer >= (amber_timer + green_timer)){
				green_timer = red_timer - amber_timer;
			}
			else{
				int half = red_timer / 2;
				int mod = red_timer % 2;
				amber_timer = half;
				green_timer = half + mod;
			}
		}
		if(timer0_flag){
			setTimer0(1000);
		}
		if(timer2_flag){
			setTimer2(250);
			blink_red();
		}
		if(timer3_flag){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		break;
	case MAN_AMBER:
		if(isButtonPressed(0)){
			status = MAN_GREEN;
			modify_val = green_timer;
			updateBuffer(3);
		}
		if(isButtonPressed(1)){
			if(modify_val >= 98){
				modify_val = 1;
			}
			else modify_val++;
			updateBuffer(2);
		}
		if(isButtonPressed(2)){
			amber_timer = modify_val;
			if(red_timer >= (amber_timer + green_timer)){
				green_timer = red_timer - amber_timer;
			}
			else{
				if((amber_timer + green_timer) <= 99){
					red_timer = amber_timer + green_timer;
				}
				else{
					red_timer = 99;
					green_timer = red_timer - amber_timer;
				}
			}
		}
		if(timer0_flag){
			setTimer0(1000);
		}
		if(timer2_flag){
			setTimer2(250);
			blink_amber();
		}
		if(timer3_flag){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		break;
	case MAN_GREEN:
		if(isButtonPressed(0)){
			status = RED_GREEN;
			setTimer1(green_timer * 1000);
			counter1 = red_timer - 1;
			counter2 = green_timer - 1;
			updateBuffer(0);
		}
		if(isButtonPressed(1)){
			if(modify_val >= 98){
				modify_val = 1;
			}
			else modify_val++;
			updateBuffer(3);
		}
		if(isButtonPressed(2)){
			green_timer = modify_val;
			if(red_timer >= (green_timer + amber_timer)){
				amber_timer = red_timer - green_timer;
			}
			else{
				if((amber_timer + green_timer) <= 99){
					red_timer = green_timer + amber_timer;
				}
				else{
					red_timer = 99;
					amber_timer = red_timer - green_timer;
				}
			}
		}
		if(timer0_flag){
			setTimer0(1000);
		}
		if(timer2_flag){
			setTimer2(250);
			blink_green();
		}
		if(timer3_flag){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		break;
	default:
		break;
	}
}
