#include "include_Ap.h"

void servoKontrol()
{
	extern uint16_t servoDeger;
	extern TIM_HandleTypeDef htim15;
		switch(Key)
		{
		case T1DEGER:
			servoDeger=94;
			OLED_SetCursor(0, 20);
			OLED_WriteString("SERVO ACISI :  0", Font_7x10, White);

			break;
		case T2DEGER:
			servoDeger=219;
			OLED_SetCursor(0, 20);
			OLED_WriteString("SERVO ACISI : 90",  Font_7x10, White);

			break;
		case T3DEGER:
			servoDeger=344;
			OLED_SetCursor(0, 20);
			OLED_WriteString("SERVO ACISI :180",  Font_7x10, White);

			break;
		case T4DEGER:
			/*
			servoDeger=469;
			OLED_SetCursor(0, 20);
			OLED_WriteString("SERVO ACISI :270",  Font_7x10, White);
*/
			currentM = &ledlerM;
			displaySelectKey=MENU_SISTEMI;
			break;

		}

		__HAL_TIM_SET_COMPARE(&htim15,TIM_CHANNEL_1,servoDeger);

}

void KeyServoKontrol()
{
	displaySelectKey=SERVO_KONTROL;
	displayClean=true;
}

