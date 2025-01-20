#ifndef __MOTOR_H
#define __MOTOR_H

void Motor_SetSpeed(int8_t Speed);
void Motor_Init(void);
void Stop(void);
void Right(void);
void Left(void);
void Straight(void);
void Motor_SetSpeedRight(int8_t Speed);
void Motor_SetSpeedLeft(int8_t Speed);

#endif
