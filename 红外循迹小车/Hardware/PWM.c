#include "stm32f10x.h"                  // Device header

void PWM_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1 ;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up ;
	TIM_TimeBaseInitStructure.TIM_Period = 1000-1;  //ARR
	TIM_TimeBaseInitStructure.TIM_Prescaler = 700-1 ;   //PSC
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter =0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStructure);
	
	TIM_OCInitTypeDef TIM_TimeInitStructure;
	TIM_OCStructInit(&TIM_TimeInitStructure);
	TIM_TimeInitStructure.TIM_OCMode =TIM_OCMode_PWM1;
	TIM_TimeInitStructure.TIM_OCPolarity =TIM_OCPolarity_High;
	TIM_TimeInitStructure.TIM_OutputState =TIM_OutputState_Enable;
	TIM_TimeInitStructure.TIM_Pulse = 0; //CCR
	TIM_OC1Init(TIM2,&TIM_TimeInitStructure);
	TIM_OC2Init(TIM2,&TIM_TimeInitStructure);
	
	TIM_Cmd(TIM2, ENABLE);
	
}

void PWM_SetCompare1(uint16_t Compare)
{
	TIM_SetCompare1 (TIM2, Compare);
}
