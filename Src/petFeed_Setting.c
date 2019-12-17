/*
 * petFeed_Setting.c
 *
 *  Created on: 24 Kas 2019
 *      Author: Orhan
 */
#include "include_Ap.h"


void amountSetting()
{
	if (durum)
	{
		switch(Key)
		{
		case T1DEGER:
			durum = false;
			*amountPtr +=50;
			if(*amountPtr>950)
			{
				*amountPtr=0;
			}
			break;

		case T2DEGER:
			durum = false;
			*amountPtr -=50;
			if(*amountPtr<0)
			{
				*amountPtr=950;
			}
			break;

		case T3DEGER:
			durum = false;
			kayitOnayDurum=true;
			displaySelectKey=MENU_SISTEMI;
			displayClean=true;
			break;

		case T4DEGER:
			durum = false;
			displaySelectKey=MENU_SISTEMI;
			displayClean=true;
			break;
		}
	}
}

void petFeedSetting()
{
	amountSetting();
	char feedYer[20];
	if(kayitOnayDurum)
	{
		BKP->DR1=feed_amount;
		kayitOnayDurum=false;
	}
	OLED_SetCursor(20, 20);
	OLED_WriteString("MAMA MIKTARI", Font_7x10, White);
	OLED_SetCursor(20, 35);
	sprintf(feedYer," %3d gr",*amountPtr);
	OLED_WriteString(feedYer, Font_11x18, White);
}

void KeyPetFeedSetting()
{
	displaySelectKey=PET_FEED_SET;
	amountPtr=&feed_amount;
	feed_amount=BKP->DR1;
	displayClean=true;
}

void petRewardFeedSetting()
{
	amountSetting();
	char feedYer[20];
	if(kayitOnayDurum)
	{
		BKP->DR2=rewardFeed_amount;
		kayitOnayDurum=false;
	}
	OLED_SetCursor(20, 20);
	OLED_WriteString("ODUL MIKTARI", Font_7x10, White);
	OLED_SetCursor(20, 35);
	sprintf(feedYer," %3d gr",*amountPtr);
	OLED_WriteString(feedYer, Font_11x18, White);
}

void KeyRewardPetFeedSetting()
{
	displaySelectKey=PET_REWARD_FEED_SET;
	amountPtr=&rewardFeed_amount;
	rewardFeed_amount=BKP->DR2;
	displayClean=true;
}

void petWaterSetting()
{
	amountSetting();
	char suYer[20];
	if(kayitOnayDurum)
	{
		BKP->DR3=water_amount;
		kayitOnayDurum=false;
	}
	OLED_SetCursor(20, 20);
	OLED_WriteString("SU MIKTARI", Font_7x10, White);
	OLED_SetCursor(20, 35);
	sprintf(suYer," %3d ml",*amountPtr);
	OLED_WriteString(suYer, Font_11x18, White);
}

void KeyPetWaterSetting()
{
	displaySelectKey=PET_WATER_SET;
	amountPtr=&water_amount;
	water_amount=BKP->DR3;
	displayClean=true;
}
