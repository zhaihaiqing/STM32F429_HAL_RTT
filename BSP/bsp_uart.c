/* Includes ------------------------------------------------------------------*/
#include "main.h"

#ifdef __GNUC__
  /* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
  
  
UART_HandleTypeDef huart1;


/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART1_UART_Init(void)
	
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */
}


void USART1_PutChar(char  ch)
{
	HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
}

//char USART1_GetChar(void)
//{
//	int ch=-1;
//	
//	if (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) != RESET)
//    {
//        ch = huart1.Instance->DR & 0xff;
//    }
//    else
//    {
//        if(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_ORE) != RESET)
//        {
//            __HAL_UART_CLEAR_OREFLAG(&huart1);
//        }
//        rt_thread_mdelay(10);
//    }
//    return ch;
//}


PUTCHAR_PROTOTYPE
{
	USART1_PutChar((char) ch);
	return ch;
}



