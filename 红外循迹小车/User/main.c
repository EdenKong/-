#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "Sensor.h"
#include "Motor.h"
#include "Key.h"


uint8_t KeyNum,leftsensor,rightsensor; 


int main(void)
{
	Motor_Init();
	Key_Init();
	
	while (1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			leftsensor = Sensor_GetLeft();
			rightsensor = Sensor_GetRight();
			if(leftsensor == 1&&rightsensor == 1)
			{
				Straight();
			}
			else if(leftsensor == 0&&rightsensor == 1)
			{
				Left();
			}
			else if(leftsensor == 1&&rightsensor == 0)
			{
				Right();
			}
		}
	}
}
