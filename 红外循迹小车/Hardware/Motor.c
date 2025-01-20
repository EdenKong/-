#include "stm32f10x.h"                  // Device header
#include "PWM.h"
#include "Motor.h"  

void Motor_Init(void)
{
	PWM_Init();
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15 ;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
}

void Motor_SetSpeedLeft(int8_t Speed)
{
	GPIO_SetBits(GPIOB ,GPIO_Pin_12);
	GPIO_ResetBits(GPIOB ,GPIO_Pin_13);
	PWM_SetCompare1(Speed);
}

void Motor_SetSpeedRight(int8_t Speed)
{
	GPIO_ResetBits(GPIOB ,GPIO_Pin_14);
	GPIO_SetBits(GPIOB ,GPIO_Pin_15);
	PWM_SetCompare1(Speed);
}

void Straight(void)
{
	Motor_SetSpeedLeft(50);
	Motor_SetSpeedRight(50);
}

void Left(void)
{
	Motor_SetSpeedLeft(0);
	Motor_SetSpeedRight(30);
}

void Right(void)
{
	Motor_SetSpeedLeft(30);
	Motor_SetSpeedRight(0);
}

void Stop(void)
{
	Motor_SetSpeedLeft(0);
	Motor_SetSpeedRight(0);
}
