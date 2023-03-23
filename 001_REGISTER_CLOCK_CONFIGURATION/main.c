
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

extern uint32_t SystemCoreClock;

uint32_t systemClock;

void RCC_Config(void){

	RCC->CR &= ~(1<<0);

	RCC->CR |= 1<<16;
	while(!(RCC->CR & (1<<17)));
	RCC->CR |= 1<<19;
	RCC->PLLCFGR=0x00000000;
	//tüm bitleri sýfýrlamadan çalýþmadý.
	//RCC->PLLCFGR |= (4<<0);

	RCC->PLLCFGR &= ~(1<<0);
	RCC->PLLCFGR &= ~(1<<1);
	RCC->PLLCFGR |= (1<<2);
	RCC->PLLCFGR &= ~(1<<3);
	RCC->PLLCFGR &= ~(1<<4);
	RCC->PLLCFGR &= ~(1<<5);

	RCC->PLLCFGR |= (168<<6);




}

int main(void)
{
	systemClock=SystemCoreClock;

	RCC_DeInit();

	SystemCoreClockUpdate();

	systemClock=SystemCoreClock;

	RCC_Config();
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
