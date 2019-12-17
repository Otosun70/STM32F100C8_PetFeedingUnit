/*
 * drv8833.c
 *
 *  Created on: Dec 11, 2019
 *      Author: Orhan
 */

#include "include_Ap.h"

void motor1_forth()
{
	HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, SET);
	HAL_GPIO_WritePin(MOTOR1_2_GPIO_Port, MOTOR1_2_Pin, RESET);
}

void motor1_back()
{
	HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, RESET);
	HAL_GPIO_WritePin(MOTOR1_2_GPIO_Port, MOTOR1_2_Pin, SET);
}

void motor2_forth()
{
	HAL_GPIO_WritePin(MOTOR2_1_GPIO_Port, MOTOR2_1_Pin, SET);
	HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, RESET);
}

void motor2_back()
{
	HAL_GPIO_WritePin(MOTOR2_1_GPIO_Port, MOTOR2_1_Pin, RESET);
	HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, SET);
}

void motor1_stop()
{
	HAL_GPIO_WritePin(MOTOR1_1_GPIO_Port, MOTOR1_1_Pin, SET);
	HAL_GPIO_WritePin(MOTOR1_2_GPIO_Port, MOTOR1_2_Pin, SET);
}

void motor2_stop()
{
	HAL_GPIO_WritePin(MOTOR2_1_GPIO_Port, MOTOR2_1_Pin, SET);
	HAL_GPIO_WritePin(MOTOR2_2_GPIO_Port, MOTOR2_2_Pin, SET);
}

void motorDriverWakeUp()
{
	HAL_GPIO_WritePin(NSLEEP_GPIO_Port, NSLEEP_Pin, SET);
}

void motorDriverSleep()
{
	HAL_GPIO_WritePin(NSLEEP_GPIO_Port, NSLEEP_Pin, RESET);
}

bool faultRead(void)
{
	return HAL_GPIO_ReadPin(NFAULT_GPIO_Port, NFAULT_Pin);
}

void motor1Kontrol()
{
		switch(Key)
		{
		case T1DEGER:
			motor1_forth();
			OLED_SetCursor(0, 20);
			OLED_WriteString("Motor_1 ileri", Font_7x10, White);

			break;
		case T2DEGER:
			motor1_back();
			OLED_SetCursor(0, 20);
			OLED_WriteString("Motor_1 geri ",  Font_7x10, White);

			break;
		case T3DEGER:
			motor1_stop();
			OLED_SetCursor(0, 20);
			OLED_WriteString("Motor_1 dur  ",  Font_7x10, White);

			break;
		case T4DEGER:
			displaySelectKey=MENU_SISTEMI;
			break;

		}


}

void KeyMotor1Kontrol()
{
	displaySelectKey=MOTOR1_KONTROL;
	displayClean=true;
}

void motor2Kontrol()
{
		switch(Key)
		{
		case T1DEGER:
			motor2_forth();
			OLED_SetCursor(0, 20);
			OLED_WriteString("Motor_2 ileri", Font_7x10, White);

			break;
		case T2DEGER:
			motor2_back();
			OLED_SetCursor(0, 20);
			OLED_WriteString("Motor_2 geri ",  Font_7x10, White);

			break;
		case T3DEGER:
			motor2_stop();
			OLED_SetCursor(0, 20);
			OLED_WriteString("Motor_2 dur  ",  Font_7x10, White);

			break;
		case T4DEGER:
			displaySelectKey=MENU_SISTEMI;
			break;

		}


}

void KeyMotor2Kontrol()
{
	displaySelectKey=MOTOR2_KONTROL;
	displayClean=true;
}
