/*
 * software_timer.h
 *
 *  Created on: Oct 22, 2023
 *      Author: Lan Vi
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TICK 10
extern int timer0_flag;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void timerRun();
void setTimer0(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
