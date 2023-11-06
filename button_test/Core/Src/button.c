/*
 * button.c
 *
 *  Created on: Oct 22, 2023
 *      Author: Lan Vi
 */

#include "button.h"
int KeyReg0[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int KeyReg3[N_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimerForKeyPress[N_BUTTON] = {200, 200, 200};
int button_flag[N_BUTTON] = {0, 0, 0};
GPIO_TypeDef* but[N_BUTTON] = {BUTTON1_GPIO_Port, BUTTON2_GPIO_Port, BUTTON3_GPIO_Port};
uint16_t pin[N_BUTTON] = {BUTTON1_Pin, BUTTON2_Pin, BUTTON3_Pin};

int isButtonPressed(int i){
	if(button_flag[i]){
		button_flag[i] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int i){
	button_flag[i] = 1;
}

void getKeyInput(){
	for(int i =0; i<N_BUTTON; i++){
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(but[i], pin[i]);
		if((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])){
			if(KeyReg3[i] != KeyReg2[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg2[i] == PRESSED_STATE){
					subKeyProcess(i);
					TimerForKeyPress[i] = 200;
				}
			}
			else{
				TimerForKeyPress[i] --;
				if(TimerForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
