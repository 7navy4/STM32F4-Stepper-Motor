#ifndef __STEPPER_H
#define __STEPPER_H
#include "stm32f4xx.h"
#include "delay.h"


void step_init(void);
void turn_cw(int32_t);
void turn_ccw(int32_t);


#endif
