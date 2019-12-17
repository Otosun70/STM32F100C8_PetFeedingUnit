/*
 * RTC_Ap.c
 *
 *  Created on: 10 Eki 2019
 *      Author: tosun_n
 */
#include "include_Ap.h"

void saatAyarla()
{
	extern RTC_HandleTypeDef hrtc;
	RTC_TimeTypeDef sTime;
//	sTime.TimeFormat=RTC_HOURFORMAT12_AM;
	sTime.Hours		=SaatAry[0];
	sTime.Minutes	=SaatAry[1];
	sTime.Seconds	=SaatAry[2];
//	sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
//	sTime.StoreOperation = RTC_STOREOPERATION_RESET;

	if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK) {
		Error_Handler();
	}
//	hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
//	RTC->CR &= ~(1<<6);


}

void alarmAyarla()
{
	extern RTC_HandleTypeDef hrtc;
	RTC_AlarmTypeDef sAlarm;

	sAlarm.AlarmTime.Hours=SaatAry[0];
	sAlarm.AlarmTime.Minutes=SaatAry[1];
	sAlarm.AlarmTime.Seconds=SaatAry[2];

	sAlarm.Alarm = RTC_ALARM_A;

	  BKP->DR6=(SaatAry[0]<<8)|(SaatAry[1]);
	  BKP->DR7=(SaatAry[2]<<8);


	if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void takvimAyarla()
{
	extern RTC_HandleTypeDef hrtc;
	  RTC_DateTypeDef DateToUpdate = {0};

	  DateToUpdate.Date = takvimAry[0];
	  DateToUpdate.Month = takvimAry[1];
	  DateToUpdate.Year = takvimAry[2];
	  DateToUpdate.WeekDay = takvimAry[3];

	  BKP->DR4=(takvimAry[0]<<8)|(takvimAry[1]);
	  BKP->DR5=(takvimAry[2]<<8)|(takvimAry[3]);

	  if (HAL_RTC_SetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    Error_Handler();
	  }

}

void saatiAyarlama(uint8_t y)
{
	ayarlaPtr=&saatAyarla;
	saat_alarm_Ayarlama(y);
}

void saat_alarm_Ayarlama(uint8_t yKonumu) {

char saatYer[16];
	if (durum) {

		switch (Key) {
		case T3DEGER:
			durum = false;
			if(kayitOnayDurum)
			{
				(ayarlaPtr)();
				displaySelectKey=MENU_SISTEMI;
				SaatAryNo=0;
				displayClean=true;
				kayitOnayDurum=false;
			}
			else	SaatAryNo ++;

			if(SaatAryNo ==3)
			{
				kayitOnayDurum=true;
			}

			break;

		case T4DEGER:
			durum = false;
			if(kayitOnayDurum)
			{
				displaySelectKey=MENU_SISTEMI;
				SaatAryNo=0;
				displayClean=true;
				kayitOnayDurum=false;
			}
			else	SaatAryNo --;

			if(SaatAryNo < 0)
			{
				SaatAryNo=2;
			}

			break;

		case T1DEGER:
			durum = false;
			SaatAry[SaatAryNo] ++;
			if(SaatAryNo==0)
			{
				if(SaatAry[SaatAryNo]>23)
				{
					SaatAry[SaatAryNo]=0;
				}
			}
			else if(SaatAryNo!=0)
			{
				if(SaatAry[SaatAryNo]>59)
				{
					SaatAry[SaatAryNo]=0;
				}
			}
			break;

		case T2DEGER:
			durum = false;
			SaatAry[SaatAryNo] --;
			if(SaatAryNo==0)
			{
				if(SaatAry[SaatAryNo]<0)
				{
					SaatAry[SaatAryNo]=23;
				}
			}
			else if(SaatAryNo!=0)
			{
				if(SaatAry[SaatAryNo]<0)
				{
					SaatAry[SaatAryNo]=59;
				}
			}
			break;

		default:
			;
		}
	}
	if(kayitOnayDurum)
	{
		kayitSorma(10,yKonumu);
	}
	sprintf(saatYer,"%02d:%02d:%02d",SaatAry[0],SaatAry[1],SaatAry[2]);
	OLED_SetCursor(10, yKonumu);
	OLED_WriteString(saatYer, Font_11x18, White);
	if(durumFlash)
	{
	OLED_SetCursor(SaatAryNo*33+10, yKonumu);
	OLED_WriteString("  ", Font_11x18, White);
	}
}

void alarmAyarlama(uint8_t y) {

	ayarlaPtr=&alarmAyarla;
	saat_alarm_Ayarlama(y);
}

void takvimiAyarlama(uint8_t y)
{

	char takvimYer[12];

//	char* weekDay[] = { "Pzt", "Sal", "Car", "Per", "Cum","Cmt", "Paz"};

		if (durum) {

			switch (Key) {
			case T3DEGER:
				durum = false;

				if(kayitOnayDurum)
				{
					takvimAyarla();
					displaySelectKey=MENU_SISTEMI;
					takvimAryNo=0;
					displayClean=true;
					kayitOnayDurum=false;
				}
				else	takvimAryNo ++;

				if(takvimAryNo ==3)
				{
					kayitOnayDurum=true;
				}
				break;

			case T4DEGER:
				durum = false;
				if(kayitOnayDurum)
				{
					displaySelectKey=MENU_SISTEMI;
					takvimAryNo=0;
					displayClean=true;
					kayitOnayDurum=false;
				}
				else	takvimAryNo --;

				if(takvimAryNo < 0)
				{
					takvimAryNo=2;
				}

				break;

			case T1DEGER:
				durum = false;
				takvimAry[takvimAryNo] ++;
				if(takvimAryNo==0)
				{
					if(takvimAry[takvimAryNo]>31)
					{
						takvimAry[takvimAryNo]=1;
					}
				}
				else if(takvimAryNo==1)
				{
					if(takvimAry[takvimAryNo]>12)
					{
						takvimAry[takvimAryNo]=1;
					}
				}
				else if(takvimAryNo==2)
				{
					if(takvimAry[takvimAryNo]>99)
					{
						takvimAry[takvimAryNo]=0;
					}
				}
				else if(takvimAryNo==3)
				{
					if(takvimAry[takvimAryNo]>7)
					{
						takvimAry[takvimAryNo]=1;
					}
				}
				break;

			case T2DEGER:
				durum = false;
				takvimAry[takvimAryNo] --;
				if(takvimAryNo==0)
				{
					if(takvimAry[takvimAryNo]<1)
					{
						takvimAry[takvimAryNo]=31;
					}
				}
				else if(takvimAryNo==1)
				{
					if(takvimAry[takvimAryNo]<1)
					{
						takvimAry[takvimAryNo]=12;
					}
				}
				else if(takvimAryNo==2)
				{
					if(takvimAry[takvimAryNo]<0)
					{
						takvimAry[takvimAryNo]=99;
					}
				}
				else if(takvimAryNo==3)
				{
					if(takvimAry[takvimAryNo]<1)
					{
						takvimAry[takvimAryNo]=7;
					}
				}
				break;

			default:
				break;
			}
		}
		if(kayitOnayDurum)
		{
			kayitSorma(10,y+10);
		}

		sprintf(takvimYer,"%02d-%02d-20%02d",takvimAry[0],takvimAry[1],takvimAry[2]);
		OLED_SetCursor(0, y);
		OLED_WriteString(takvimYer, Font_11x18, White);
		OLED_SetCursor(30, y+20);
//		OLED_WriteString(weekDay[takvimAry[3]], Font_7x10, White);  //
		if(durumFlash)
		{
			if(takvimAryNo<2)
			{
				OLED_SetCursor(takvimAryNo*33, y);
				OLED_WriteString("  ", Font_11x18, White);
			}
			else if(takvimAryNo==2)
			{
				OLED_SetCursor(takvimAryNo*33+22, y);
				OLED_WriteString("  ", Font_11x18, White);
			}
			else if(takvimAryNo==3)
			{
				OLED_SetCursor(30, y+20);
				OLED_WriteString("            ", Font_7x10, White);
			}

		}
}
/*Geçerli saat bilgisini okuyup saat ayar ekranına yönlendirecek Key1 değerini ayarlar */
void KeySaatiAyarlama()
{
	extern RTC_HandleTypeDef hrtc;
	RTC_TimeTypeDef sTimeGet;
	HAL_RTC_GetTime(&hrtc, &sTimeGet, RTC_FORMAT_BIN);

	SaatAry[0]=sTimeGet.Hours;
	SaatAry[1]=sTimeGet.Minutes;
	SaatAry[2]=sTimeGet.Seconds;

	displaySelectKey=SAATI_AYARLAMA;
	SaatAryNo=0;
	displayClean=true;

}
/*Geçerli alarm bilgisini okuyup alarm ayar ekranına yönlendirecek Key1 değerini ayarlar */
void KeyAlarmAyarlama()
{
	extern RTC_HandleTypeDef hrtc;
	RTC_AlarmTypeDef sAlarmGet;
	HAL_RTC_GetAlarm(&hrtc, &sAlarmGet,RTC_ALARM_A, RTC_FORMAT_BIN);

	SaatAry[0]=sAlarmGet.AlarmTime.Hours;
	SaatAry[1]=sAlarmGet.AlarmTime.Minutes;
	SaatAry[2]=sAlarmGet.AlarmTime.Seconds;

	displaySelectKey=ALARM_AYARLAMA;
	SaatAryNo=0;
	displayClean=true;

}
/*Geçerli takvim bilgisini okuyup saat ayar ekranına yönlendirecek Key1 değerini ayarlar */

void KeyTakvimiAyarlama()
{

	extern RTC_HandleTypeDef hrtc;
	RTC_DateTypeDef sDateGet;
	HAL_RTC_GetDate(&hrtc, &sDateGet, RTC_FORMAT_BIN);

	takvimAry[0]=sDateGet.Date;
	takvimAry[1]=sDateGet.Month;
	takvimAry[2]=sDateGet.Year;
	takvimAry[3]=sDateGet.WeekDay;

	displaySelectKey=TAKVIMI_AYARLAMA;
	takvimAryNo=0;
	displayClean=true;
}



void kayitSorma(uint8_t x1,uint8_t y1)
{
	if(durumFlash)
	{
		OLED_SetCursor(x1, y1+20);
		OLED_WriteString("Kaydedilsin mi?", Font_7x10, White);
	}
	else
	{
		OLED_SetCursor(x1, y1+20);
		OLED_WriteString("               ", Font_7x10, White);
	}
}

bool alarmRead(void)
{
	return ((RTC->CRL & RTC_CRL_ALRF_Msk)>> RTC_CRL_ALRF_Pos);//RTC_CRL_ALRF_Pos
}

void alarmDurdur()
{
	RTC->CRL &=~RTC_CRL_ALRF;;
}

void alarmDeneme(uint8_t alarmDurdurmaKeyDegeri)
{
	if(Key==alarmDurdurmaKeyDegeri)
	{
		alarmDurdur();
	}

	if(alarmRead())
	{
		HAL_GPIO_WritePin(LED_ALARM_GPIO_Port, LED_ALARM_Pin,SET);
		if(!displayDurum)
		{
			displayDurum=true;
			OLED_Init();
		}
	}
	else
	{
		HAL_GPIO_WritePin(LED_ALARM_GPIO_Port, LED_ALARM_Pin,RESET);
	}
}

void alarmGoster()
{
	char aShowAlarm[16];
	extern RTC_HandleTypeDef hrtc;

	RTC_AlarmTypeDef sAlarmGet;

	/* Get the RTC current Time */
	HAL_RTC_GetAlarm(&hrtc, &sAlarmGet,RTC_ALARM_A, RTC_FORMAT_BIN);

	/* Display time Format : hh:mm:ss */
	sprintf(aShowAlarm, "%2d:%02d:%02d", sAlarmGet.AlarmTime.Hours, sAlarmGet.AlarmTime.Minutes, sAlarmGet.AlarmTime.Seconds);
	OLED_SetCursor(30, 0);
	OLED_WriteString(aShowAlarm, Font_7x10, White);
}

void saatGoster()
{
	char aShowTime[16];
	extern RTC_HandleTypeDef hrtc;

	RTC_TimeTypeDef sTimeGet;
	RTC_DateTypeDef sDateGet;

	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &sTimeGet, RTC_FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDateGet, RTC_FORMAT_BIN);

	/* Display time Format : hh:mm:ss */
	sprintf(aShowTime, "%2d:%02d:%02d", sTimeGet.Hours, sTimeGet.Minutes, sTimeGet.Seconds);
	OLED_SetCursor(30, 0);
	OLED_WriteString(aShowTime, Font_7x10, White);
}

void takvimGoster()
{
	char aShowDate[15];
	char aShowTime[15];

	extern RTC_HandleTypeDef hrtc;

	RTC_TimeTypeDef sTimeGet;
	RTC_DateTypeDef sDateGet;

//	  const char* weekD[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun", "??"};
	char* weekDay[] ={ "Pzt", "Sal", "Car", "Per", "Cum", "Cmt", "Paz"}; //{ "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday", "Sunday"};


	/* Get the RTC current Time */
	HAL_RTC_GetTime(&hrtc, &sTimeGet, RTC_FORMAT_BIN);
	/* Display time Format : hh:mm:ss */
	sprintf(aShowTime, "%2d:%02d", sTimeGet.Hours, sTimeGet.Minutes);//sTimeGet.Seconds
	OLED_SetCursor(20, 20);
	OLED_WriteString(aShowTime, Font_16x26, White);
	sprintf(aShowTime, "%02d",sTimeGet.Seconds);
	OLED_SetCursor(105, 32);
	OLED_WriteString(aShowTime, Font_7x10, White);

	/* Get the RTC current Date */
	HAL_RTC_GetDate(&hrtc, &sDateGet, RTC_FORMAT_BIN);
	/* Display date Format : mm-dd-yy */
	sprintf(aShowDate, "%02d-%02d-%2d", sDateGet.Date, sDateGet.Month,
			2000 + sDateGet.Year);
	OLED_SetCursor(10, 50);
	OLED_WriteString(aShowDate, Font_7x10, White);
	OLED_SetCursor(95, 50);
	OLED_WriteString(weekDay[sDateGet.WeekDay-1], Font_7x10, White);  //
}
void takvimGeriYukleme()
{
	takvimAry[0]=(BKP->DR4>>8);
	takvimAry[1]=(BKP->DR4)&0xFF;
	takvimAry[2]=(BKP->DR5>>8);
	takvimAry[3]=(BKP->DR5)&0xFF;
	takvimAyarla();
}

void alarmGeriYukleme()
{
	  SaatAry[0]=(BKP->DR6>>8);
	  SaatAry[1]=(BKP->DR6)&0xFF;
	  SaatAry[2]=(BKP->DR7>>8);
	  alarmAyarla();
}
