/*
 * petFeeding.c
 *
 *  Created on: Dec 11, 2019
 *      Author: Orhan
 */
#include "include_Ap.h"

extern uint16_t deger[5];

void giveFeed()

{
	motorDriverWakeUp();

	if(deger[0]>3000)
	{
		motor1_forth();
		motor2_forth();
	}
	else if(deger[0]>2000)
	{
		motor1_stop();
		motor2_stop();
	}
	else
	{
		motor1_back();
		motor2_back();
	}
}

void fault_Durum()
{
	faultDurum=faultRead();

	if(faultDurum)
	{
		HAL_GPIO_WritePin(LED_ALARM_GPIO_Port,LED_ALARM_Pin,RESET);
	}
	else
	{
		HAL_GPIO_WritePin(LED_ALARM_GPIO_Port,LED_ALARM_Pin,SET);

	}
}

void sleepMode()
{
	  switch(sleepDurum)
	  {
	  case true:
		  motorDriverWakeUp();
	  break;

	  case false:
		  motorDriverSleep();
	  break;

	  default:
		  motorDriverWakeUp();

	  }
}
