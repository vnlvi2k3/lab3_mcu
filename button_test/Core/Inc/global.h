/*
 * global.h
 *
 *  Created on: Oct 23, 2023
 *      Author: Lan Vi
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "fsm_automatic.h"

#define INIT 1
#define RED_GREEN 2
#define RED_AMBER 3
#define GREEN_RED 4
#define AMBER_RED 5

#define MAN_RED 10
#define MAN_AMBER 11
#define MAN_GREEN 12

#define DEFAULT_RED 5
#define DEFAULT_AMBER 2
#define DEFAULT_GREEN 3

extern int status;
int red_timer;
int amber_timer;
int green_timer;
int index_led;
int led_buffer[4];
int modify_val;
int counter1;
int counter2;
void initialize();
void red_green();
void red_amber();
void green_red();
void amber_red();

void turn_red();
void turn_amber();
void turn_green();

void update7SEG(int index);
void updateBuffer(int mode);

#endif /* INC_GLOBAL_H_ */
