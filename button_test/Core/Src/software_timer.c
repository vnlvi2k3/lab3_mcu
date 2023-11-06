/*
 * software_timer.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Lan Vi
 */

#include "software_timer.h"

int timer0_flag;
int timer0_count;
int timer1_flag;
int timer1_count;
int timer2_flag;
int timer2_count;
int timer3_flag;
int timer3_count;

void setTimer0(int duration){
	timer0_count = duration / TICK;
	timer0_flag = 0;
}

void setTimer1(int duration){
	timer1_count = duration / TICK;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_count = duration / TICK;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3_count = duration / TICK;
	timer3_flag = 0;
}

void timerRun(){
	if(timer0_count > 0){
		timer0_count --;
		if(timer0_count <= 0){
			timer0_flag = 1;
		}
	}
	if(timer1_count > 0){
		timer1_count --;
		if(timer1_count <= 0){
			timer1_flag = 1;
		}
	}
	if(timer2_count > 0){
		timer2_count --;
		if(timer2_count <= 0){
			timer2_flag = 1;
		}
	}
	if(timer3_count > 0){
		timer3_count --;
		if(timer3_count <= 0){
			timer3_flag = 1;
		}
	}
}
