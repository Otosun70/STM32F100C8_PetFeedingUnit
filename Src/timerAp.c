/*
 * timerAp.c
 *
 *  Created on: 7 Eki 2019
 *      Author: tosun_n
 */
#include "timerAp.h"
#include "main.h"
/*
void InitTimer14(void){
RCC->APB1ENR |= RCC_APB1ENR_TIM14EN; // Enable clock for TIM7
TIM14->CR1 &= ~CEN; // Disable TIM7 interrupt
TIM14->PSC = 256;
TIM14->ARR = 45000;
NVIC_EnableIRQ(TIM14_IRQn);
TIM14->DIER |= UIE; // Enable TIM7 interrupt
TIM14->CR1 |= CEN; // TIM7 enable
}


void TIM14_IRQHandler (void) {
TIM14->SR &= ~UIF; // Clear UIF
//HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);

if(durumFlash)
{
	durumFlash=false;
}
else
{
	durumFlash=true;
}
}
*/


void InitTimer7(void){
RCC->APB1ENR |= RCC_APB1ENR_TIM7EN; // Enable clock for TIM7
TIM7->CR1 &= ~CEN; // Disable TIM7 interrupt
TIM7->PSC = 550;
TIM7->ARR = 3750*2;//RCC_PLL_MUL4
NVIC_EnableIRQ(TIM7_IRQn);
TIM7->DIER |= UIE; // Enable TIM7 interrupt
TIM7->CR1 |= CEN; // TIM7 enable
}


void TIM7_IRQHandler (void) {
TIM7->SR &= ~UIF; // Clear UIF
//HAL_GPIO_TogglePin(LD6_GPIO_Port, LD6_Pin);
if(durumFlash)
{
	durumFlash=false;
}
else
{
	durumFlash=true;
}
}
