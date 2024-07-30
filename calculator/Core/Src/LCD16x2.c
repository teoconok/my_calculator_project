/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    LCD16x2.c
  * @brief   LCD function.
  ******************************************************************************
  * @attention
  *
  * Library source: https://www.youtube.com/watch?v=dQbnnh9PGdc (Customization)
  *
  ******************************************************************************
  */
/* USER CODE END Header */

#include "LCD16x2.h"
#include "string.h"
#include "stdio.h"

void LCD_Write(uint8_t data)
{
	HAL_GPIO_WritePin(LCD_PORT, LCD_D4, ((data >> 0) & 0x01));
	HAL_GPIO_WritePin(LCD_PORT, LCD_D5, ((data >> 1) & 0x01));
	HAL_GPIO_WritePin(LCD_PORT, LCD_D6, ((data >> 2) & 0x01));
	HAL_GPIO_WritePin(LCD_PORT, LCD_D7, ((data >> 3) & 0x01));

// active enable pin
	HAL_GPIO_WritePin(LCD_PORT,LCD_E, 1);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_PORT,LCD_E, 0);
}
void LCD_Send(uint8_t Reg, uint8_t data)
{
	HAL_GPIO_WritePin(LCD_PORT, LCD_RS, Reg);   // Reg = 0 : data register ; Reg = 1 : command register
	LCD_Write(data >> 4);
	LCD_Write(data);
}
void LCD_Init()
{
	HAL_GPIO_WritePin(LCD_PORT, LCD_RW, 0);    // choose write mode

	LCD_Send(cmd_reg, 0x33);                   // initiate command
	LCD_Send(cmd_reg, 0x32);                  // initiate command
	LCD_Send(cmd_reg, 0x28);                   // 4 bit mode, 2 row, 5x7
	LCD_Send(cmd_reg, 0x0C);                   // display screen and pointer
	LCD_Send(cmd_reg, 0x06);                  // increase pointer
	LCD_Send(cmd_reg, 0x01);                   // Clear all data on LCD
}
void LCD_Clear()                                //Clear all data on LCD
{
	LCD_Send(cmd_reg, 0x01);
}
void LCD_Location(uint8_t x, uint8_t y)         // choose location
{
  if(y == 0)
	  LCD_Send(cmd_reg, 0x80 + x);
  else if(y == 1)
	  LCD_Send(cmd_reg, 0xC0 + x);
}
void LCD_Write_String(char* string){              // Display data on LCD
	for(uint8_t i = 0; i < strlen(string); i++)
	{
		LCD_Send(data_reg, string[i]);
	}
}
void LCD_Write_Number(double number)                 // Display number on LCD
{
	char buffer[15];
	for (int i=0;i<15;i++){
		buffer[i]='\0';
	}
	sprintf(buffer, "%.4f", number);
	int z=0;
    for (int i=0; i<strlen(buffer); i++){
        if (buffer[i] == '.'){
            z = i;
            for (int i = z+1; i<strlen(buffer); i++){
                if (buffer[i]>='1' && buffer[i]<='9'){
                z = i+1;
                }
            }
            break;
        }
    }
    for (int i = z; i<strlen(buffer); i++){
        buffer[i]='\0';
    }
	LCD_Write_String(buffer);
}
