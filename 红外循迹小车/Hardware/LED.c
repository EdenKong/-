#include "stm32f10x.h"                  // Device header

void LED_Init(void)//LED GPIO初始化
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits (GPIOA ,GPIO_Pin_1 | GPIO_Pin_2);//让pin1和pin2初始配置成高电平，这样初始不会亮
}

void LED1_ON(void)//LED1亮
{
	GPIO_ResetBits (GPIOA ,GPIO_Pin_1);
}

void LED1_OFF(void)//LED1灭
{
	GPIO_SetBits (GPIOA ,GPIO_Pin_1);
}

void LED1_Turn(void)//LED1亮灭转换
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_1)==0)//此时LED1接口为低电平，亮灯
	{
		GPIO_SetBits (GPIOA, GPIO_Pin_1);//亮灯时触发则熄灯
	}
	else
	{
		GPIO_ResetBits (GPIOA, GPIO_Pin_1);//熄灯时触发则亮灯
	}
}

void LED2_ON(void)//LED2亮
{
	GPIO_ResetBits (GPIOA ,GPIO_Pin_2);
}

void LED2_OFF(void)//LED2灭
{
	GPIO_SetBits (GPIOA ,GPIO_Pin_2);
}

void LED2_Turn(void)//LED2亮灭转换
{
	if(GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_2)==0)//此时LED1接口为低电平，亮灯
	{
		GPIO_SetBits (GPIOA, GPIO_Pin_2);//亮灯时触发则熄灯
	}
	else
	{
		GPIO_ResetBits (GPIOA, GPIO_Pin_2);//熄灯时触发则亮灯
	}
}
