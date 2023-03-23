
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

extern uint32_t SystemCoreClock;

uint32_t systemClock;

void RCC_Config(void){

	// 8 000 000 -> 16 000 000
	RCC->CR &= ~(1<<0); //HSI OFF

	RCC->CR |= 1<<16;	//HSE ON
	while(!(RCC->CR & (1<<17)));	//Wait HSE active
	RCC->CR |= 1<<19;
	RCC->PLLCFGR=0x00000000;  //PLLCFGR Reset
	//tüm bitleri sýfýrlamadan çalýþmadý.
	//RCC->PLLCFGR |= (4<<0);
	RCC->PLLCFGR |=(1<<22); //PLL Source HSE

	RCC->PLLCFGR &= ~(1<<0);
	RCC->PLLCFGR &= ~(1<<1);
	RCC->PLLCFGR |= (1<<2); 	//PLL M 4
	RCC->PLLCFGR &= ~(1<<3);
	RCC->PLLCFGR &= ~(1<<4);
	RCC->PLLCFGR &= ~(1<<5);

	RCC->PLLCFGR |= (168<<6);	//PLL N 168
	//PLL P 2 because PLLCFGR Reset bit 16 17 are 0 so PLLP=2
	RCC->CR |=(1<<24); //PLL ON
	while(!(RCC->CR & (1<<25))); //Wait PLL active

	RCC->CFGR &=~(1<<0);
	RCC->CFGR |=(1<<1); //System clock is PLL

	while(!(RCC->CFGR & (1<<1))); // sadece 1. Bit PLL durumunda 1 olduðu için onu kontrol ediyoruz döngü içerisinde.


}

int main(void)
{


	RCC_Config();

	SystemCoreClockUpdate();

	systemClock=SystemCoreClock;

  while (1)
  {

  }
}


/*
 * Callback used by stm32f4_discovery_audio_codec.c.
 * Refer to stm32f4_discovery_audio_codec.h for more info.
 */
void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

/*
 * Callback used by stm324xg_eval_audio_codec.c.
 * Refer to stm324xg_eval_audio_codec.h for more info.
 */
uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
