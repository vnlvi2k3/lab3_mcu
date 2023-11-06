/*
 * fsm_automatic.c
 *
 *  Created on: Oct 23, 2023
 *      Author: Lan Vi
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = RED_GREEN;
		initialize();
		updateBuffer(0);
		setTimer0(1000);
		setTimer1(green_timer * 1000);
		setTimer3(100);
		break;
	case RED_GREEN:
		red_green();
		if(timer0_flag){
			setTimer0(1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
			updateBuffer(0);
		}
		if(timer1_flag == 1){
			counter2 = amber_timer - 1;
			status = RED_AMBER;
			setTimer1(amber_timer * 1000);
			updateBuffer(0);
		}
		if(timer3_flag == 1){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(isButtonPressed(0)){
			status = MAN_RED;
			setTimer2(250);
			modify_val = red_timer;
			updateBuffer(1);
		}
		break;
	case RED_AMBER:
		red_amber();
		if(timer0_flag){
			setTimer0(1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
			updateBuffer(0);
		}
		if(timer1_flag == 1){
			counter1 = green_timer - 1;
			counter2 = red_timer - 1;
			status = GREEN_RED;
			setTimer1(green_timer * 1000);
			updateBuffer(0);
		}
		if(timer3_flag == 1){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(isButtonPressed(0)){
			status = MAN_RED;
			setTimer2(250);
			modify_val = red_timer;
			updateBuffer(1);
		}
		break;
	case GREEN_RED:
		green_red();
		if(timer0_flag){
			setTimer0(1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
			updateBuffer(0);
		}
		if(timer1_flag == 1){
			counter1 = amber_timer - 1;
			status = AMBER_RED;
			setTimer1(amber_timer * 1000);
			updateBuffer(0);
		}
		if(timer3_flag == 1){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(isButtonPressed(0)){
			status = MAN_RED;
			setTimer2(250);
			modify_val = red_timer;
			updateBuffer(1);
		}
		break;
	case AMBER_RED:
		amber_red();
		if(timer0_flag){
			setTimer0(1000);
			if(counter1 > 0) counter1 --;
			if(counter2 > 0) counter2 --;
			updateBuffer(0);
		}
		if(timer1_flag == 1){
			counter1 = red_timer - 1;
			counter2 = green_timer - 1;
			status = RED_GREEN;
			setTimer1(green_timer * 1000);
			updateBuffer(0);
		}
		if(timer3_flag == 1){
			setTimer3(100);
			if(index_led >= 4){
				index_led = 0;
			}
			update7SEG(index_led++);
		}
		if(isButtonPressed(0)){
			status = MAN_RED;
			setTimer2(250);
			modify_val = red_timer;
			updateBuffer(1);
		}
		break;
	default:
		break;
	}
}
