/*
 * petFeed_Setting.h
 *
 *  Created on: 24 Kas 2019
 *      Author: Orhan
 */

#ifndef PETFEED_SETTING_H_
#define PETFEED_SETTING_H_

int16_t feed_amount;
int16_t rewardFeed_amount;
int16_t water_amount;
int16_t *amountPtr;

void amountSetting();

void petFeedSetting();

void KeyPetFeedSetting();

void petWaterSetting();

void KeyPetWaterSetting();

void petRewardFeedSetting();

void KeyRewardPetFeedSetting();

#endif /* PETFEED_SETTING_H_ */
