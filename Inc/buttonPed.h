#ifndef __BUTTONPED_H
#define __BUTTONPED_H


#include "stdio.h"
#include "stdbool.h"
#include "stm32f1xx_hal.h"

#define T1DEGER 		216
#define T2DEGER 		232
#define T3DEGER 		120
#define T4DEGER 		184
#define T3VT4DEGER 		56
#define T4VT2DEGER 		168
#define T0DEGER 		248
#define TAKVIMI_AYARLAMA 66
#define ALARM_AYARLAMA 	67
#define SERVO_KONTROL 	68
#define SAATI_AYARLAMA 	65
#define PET_FEED_SET 	69
#define PET_WATER_SET 	70
#define PET_REWARD_FEED_SET 	71
#define MOTOR1_KONTROL	72
#define MOTOR2_KONTROL	73

#define MENU_SISTEMI 	T3VT4DEGER
#define MENUEXIT 		T4VT2DEGER
#define GIRIS_EKRANI 	T4VT2DEGER

uint8_t Key;
uint8_t displaySelectKey;

bool durum,displayClean,durumFlash,kayitOnayDurum,uykuSayacDurum,displayDurum,faultDurum,sleepDurum;

void ButtonPed_Init(void);

void button_Read(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin1,uint16_t GPIO_Pin2,uint16_t GPIO_Pin3,uint16_t GPIO_Pin4,uint16_t GPIO_Pin5);



#endif /* __BUTTONPED_H */
