
#ifndef __BSP_UART_H
#define __BSP_UART_H


extern UART_HandleTypeDef huart1;

void MX_USART1_UART_Init(void);
void USART1_PutChar(char  ch);

#endif


