#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA ,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA ,&GPIO_InitStruct);
	
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_8 )==0)//如果pin1为低电平，说明GND下拉，表示联通(按键按下)
	{
		Delay_ms(20);//消抖
		while(GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_8 )==0)//如果按住按键一直不松，则卡在while循环中
		Delay_ms(20);
		KeyNum =1;
	}
	return KeyNum;
}
