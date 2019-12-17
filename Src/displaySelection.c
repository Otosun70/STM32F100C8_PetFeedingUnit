/*
 * displaySelection.c
 *
 *  Created on: 24 Kas 2019
 *      Author: Orhan
 */
#include "include_Ap.h"

/*Ekranda gösterilecek unsurları Key1 değerine göre seçer */
void displaySelect()
{

	button_Read(GPIOB,KEY_1_Pin,KEY_2_Pin,KEY_3_Pin,KEY_4_Pin,KEY_5_Pin); /*Menu ekranına geçirecek kısayol tuş kombinasyonunu algılayıp Key1 değerine aktarır*/
	if(Key==MENU_SISTEMI)
	{
		displaySelectKey=Key;
		displayClean=true;
	}
	switch(displaySelectKey)
	{
	case MENU_SISTEMI :
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
//		alarmDurdur();
		menuSistemi(6);
		break;

	case SAATI_AYARLAMA:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		saatiAyarlama(30);
		break;
	case TAKVIMI_AYARLAMA:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		takvimiAyarlama(20);
		break;
	case ALARM_AYARLAMA:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		alarmAyarlama(20);
		break;

	case GIRIS_EKRANI:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		alarmGoster();
		takvimGoster();
	//	ADC_degerleriGosterme();
		break;

	case SERVO_KONTROL:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		servoKontrol();
//		takvimGoster();

		break;

	case PET_FEED_SET:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		petFeedSetting();

		break;
	case PET_WATER_SET:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		petWaterSetting();

		break;
	case PET_REWARD_FEED_SET:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		petRewardFeedSetting();

		break;
	case MOTOR1_KONTROL:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		motor1Kontrol();

		break;
	case MOTOR2_KONTROL:
		if(displayClean)
		{
		displayClean=false;
		OLED_Fill(Black);
		}
		motor2Kontrol();

		break;

	}
}

void menuExit()
{
	displaySelectKey=MENUEXIT;
	currentM = &menu1M;
	displayClean=true;
}
