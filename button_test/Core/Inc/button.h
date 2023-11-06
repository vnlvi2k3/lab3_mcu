/*
 * button.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lan Vi
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

#include "main.h"

#define N_BUTTON 3
int isButtonPressed(int i);
void getKeyInput();

#endif /* INC_BUTTON_H_ */
