/*
 * drv8833.h
 *
 *  Created on: Dec 11, 2019
 *      Author: Orhan
 */

#ifndef DRV8833_H_
#define DRV8833_H_
/*
#define NSLEEP_Pin GPIO_PIN_5
#define NSLEEP_GPIO_Port GPIOA

#define MOTOR1_1_Pin GPIO_PIN_6
#define MOTOR1_1_Port GPIOA

#define MOTOR1_2_Pin GPIO_PIN_7
#define MOTOR1_2_Port GPIOA

#define MOTOR2_2_Pin GPIO_PIN_0
#define MOTOR2_2_Port GPIOB

#define MOTOR2_1_Pin GPIO_PIN_1
#define MOTOR2_1_Port GPIOB

#define NFAULT_Pin GPIO_PIN_2
#define NFAULT_GPIO_Port GPIOB
*/
void motor1_forth();

void motor1_back();

void motor2_forth();

void motor2_back();

void motor1_stop();

void motor2_stop();

void motorDriverWakeUp();

void motorDriverSleep();

bool faultRead(void);

void motor1Kontrol();

void motor2Kontrol();

void KeyMotor1Kontrol();

void KeyMotor2Kontrol();


#endif /* DRV8833_H_ */
