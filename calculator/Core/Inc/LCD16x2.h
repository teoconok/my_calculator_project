/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    LCD16x2.h
  * @brief   LCD function.
  ******************************************************************************
  * @attention
  *
  * Library source: https://www.youtube.com/watch?v=dQbnnh9PGdc
  *
  ******************************************************************************
  */
/* USER CODE END Header */
#ifndef __LCD16X2_H__
#define __LCD16X2_H__

#include "stm32f1xx_hal.h"

// define Pin
#define LCD_PORT    GPIOA

#define LCD_RS      GPIO_PIN_0
#define LCD_RW      GPIO_PIN_1
#define LCD_E       GPIO_PIN_2

#define LCD_D4      GPIO_PIN_3
#define LCD_D5      GPIO_PIN_4
#define LCD_D6      GPIO_PIN_5
#define LCD_D7      GPIO_PIN_6

#define cmd_reg     0
#define data_reg    1

// cac ham
void LCD_Write(uint8_t data);
void LCD_Send(uint8_t Reg, uint8_t data);  // send data to LCD
void LCD_Init(); 			   // initiate LCD
void LCD_Clear(); 			   // clear LCD screen
void LCD_Location(uint8_t x, uint8_t y);   // x, y coordinates on LCD
void LCD_Write_String(char* string);	   // display characters on LCD
void LCD_Write_Number(double number);	   // display numbers on LCD


#endif
