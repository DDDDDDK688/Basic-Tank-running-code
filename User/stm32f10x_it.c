/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTI
  
  AL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "stm32f10x_tim.h"
#include "bsp_usart.h"
extern float speed;
extern int i;
/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  None
  * @retval None
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  None
  * @retval None
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

// 串口中断服务函数
void DEBUG_USART_IRQHandler(void)
{
  uint8_t ucTemp;
	if(USART_GetITStatus(DEBUG_USARTx,USART_IT_RXNE)!=RESET)
	{		
		ucTemp = USART_ReceiveData(DEBUG_USARTx);
		USART_SendData(DEBUG_USARTx,ucTemp);

		printf("Getchar: %c\n",ucTemp);
			/* 根据字符指令控制RGB彩灯颜色 */
			switch (ucTemp)
			{
//			case '1':
//				speed=0;			
//				TIM_SetCompare1(TIM1,speed);
//				TIM_SetCompare2(TIM1,speed);
//				printf("speed=0\n");
//				break;
			case '2':
				speed=100;
				TIM_SetCompare1(TIM1,speed);
				TIM_SetCompare2(TIM1,speed);
//				GPIO_SetBits(GPIOC, GPIO_Pin_13);
				printf("speed=50\n");
				break;
//			case '3':
//				speed=100;
//				TIM_SetCompare1(TIM1,speed);
//				TIM_SetCompare2(TIM1,speed);
//				printf("speed=100\n");
//				break;
//			case '4':
//				speed=150;
//				TIM_SetCompare1(TIM1,speed);
//				TIM_SetCompare2(TIM1,speed);
//				printf("speed=150\n");
//				break;
//			case '5':
//				speed=200;
//				TIM_SetCompare1(TIM1,speed);
//				TIM_SetCompare2(TIM1,speed);
//				printf("speed=200\n");
//				break;
			case 'W':
				i=1;			
				GPIO_ResetBits(GPIOB, GPIO_Pin_12);
				GPIO_ResetBits(GPIOB, GPIO_Pin_14);
				TIM_SetCompare1(TIM1,199);
				TIM_SetCompare2(TIM1,199);
				printf("UP\n");
				break;
			case 'S':
				i=2;
				GPIO_ResetBits(GPIOB, GPIO_Pin_13);
				GPIO_ResetBits(GPIOB, GPIO_Pin_15);
				TIM_SetCompare1(TIM1,199);
				TIM_SetCompare2(TIM1,199);
				printf("DOWN\n");
				break;
			case 'A':
				i=3;
				TIM_SetCompare1(TIM1,199);
				TIM_SetCompare2(TIM1,100);
				printf("LEFT\n");
				break;
			case 'D':
				i=4;
				TIM_SetCompare1(TIM1,100);
				TIM_SetCompare2(TIM1,199);
				printf("RIGHT\n");
				break;
			
			case '1':
				i=0;			
				GPIO_ResetBits(GPIOB, GPIO_Pin_12);
				GPIO_ResetBits(GPIOB, GPIO_Pin_14);
				GPIO_ResetBits(GPIOB, GPIO_Pin_13);
				GPIO_ResetBits(GPIOB, GPIO_Pin_15);
				printf("STOP\n");
				break;
			default:
				printf("Please try again \n");
				break;
		}

	}	 
}

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
