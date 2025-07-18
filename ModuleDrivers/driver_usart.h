/*  Copyright (s) 2019 深圳百问网科技有限公司
 *  All rights reserved
 * 
 * 文件名称：driver_usart.h
 * 摘要：
 *  
 * 修改历史     版本号        Author       修改内容
 *--------------------------------------------------
 * 2020.6.6      v01        百问科技      创建文件
 *--------------------------------------------------
*/

#ifndef __DRIVER_USART_H
#define __DRIVER_USART_H

#include "stm32f1xx_hal.h"

/*
 *  函数名：EnableDebugIRQ
 *  功能描述：使能USART1的中断
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
*/
void EnableDebugIRQ(void);

/*
 *  函数名：DisableDebugIRQ
 *  功能描述：失能USART1的中断
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
*/
void DisableDebugIRQ(void);

void EnableUART3IRQ(void);

#endif /* __DRIVER_USART_H */
