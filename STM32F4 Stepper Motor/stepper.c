#include "stm32f4xx.h"
#include "stepper.h"
#include "delay.h"




void step_init()
	{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

		GPIO_InitTypeDef GPIO_InitStruct;
 		GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13| GPIO_Pin_14| GPIO_Pin_15;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
		GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
		GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_Init(GPIOD,&GPIO_InitStruct);
	}


void turn_ccw(int32_t speed)
  {
		GPIO_Write(GPIOD,GPIO_Pin_12);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_12| GPIO_Pin_13);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_13);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_14|GPIO_Pin_13);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_14);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_14|GPIO_Pin_15);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_15);
    Delay(speed);
    GPIO_Write(GPIOD,GPIO_Pin_15|GPIO_Pin_12);
		Delay(speed);
  }
	
void turn_cw(int32_t speed)
	{
		GPIO_Write(GPIOD,GPIO_Pin_12);
    Delay(speed);
		GPIO_Write(GPIOD,GPIO_Pin_15|GPIO_Pin_12);
		Delay(speed);
		GPIO_Write(GPIOD,GPIO_Pin_15);
    Delay(speed);
		GPIO_Write(GPIOD,GPIO_Pin_14|GPIO_Pin_15);
    Delay(speed);
		GPIO_Write(GPIOD,GPIO_Pin_14);
    Delay(speed);
		GPIO_Write(GPIOD,GPIO_Pin_14|GPIO_Pin_13);
    Delay(speed);
		GPIO_Write(GPIOD,GPIO_Pin_12| GPIO_Pin_13);
    Delay(speed);
		
	}
	
		
		

