#include "stm32f10x.h"
#include "motor.h"
#include "oled.h"
#include "bsp_usart.h"

float speed;
int i,j;
int main(void)
{	

	delay_init();
	USART_Config();
	Motor_Init();
	Motor_PWMA_Init(199,71);
	OLED_Init();
	OLED_DisplayTurn(0);
	OLED_ColorTurn(0);
	speed = 199;
	i = 0;
	j = 0;
	TIM_SetCompare1(TIM1,199);
	TIM_SetCompare2(TIM1,199);
	printf("Ready\n");


  while(1)
	{	

		OLED_ShowNum(0,0,speed,3,16);
		OLED_Refresh();
		
       
		if(i==1)
		{

			GPIO_SetBits(GPIOB, GPIO_Pin_13);
			GPIO_SetBits(GPIOB, GPIO_Pin_15);
			
		}	
		
		if(i==2)
		{

			GPIO_SetBits(GPIOB, GPIO_Pin_12);
			GPIO_SetBits(GPIOB, GPIO_Pin_14);
			
		}
		
//		if(i==3)
//		{
//			TIM_SetCompare1(TIM1,speed);
//			TIM_SetCompare2(TIM1,99.5);
//			
//		}
//		
//		if(i==4)
//		{
//			TIM_SetCompare1(TIM1,99.5);
//			TIM_SetCompare2(TIM1,speed);
//		}

	}	
}

