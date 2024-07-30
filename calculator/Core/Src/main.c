/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Author: Pham Van Tin (teocon)
  * Library source: https://www.youtube.com/watch?v=dQbnnh9PGdc
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "string.h"
#include "LCD16x2.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
char num_op[17] = {'1','4','7','d','2','5','8','0','3','6','9','=','+','-', '*', '/'}; // define button
char Key_Scan(void)
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15, 1);
	if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)){
		// press button 7
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7));
		return num_op[0];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)){
		// press button 8
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
		return num_op[1];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)){
		// press button 9
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
		return num_op[2];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)){
		// press button 10
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10));
		return num_op[3];
	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_14 | GPIO_PIN_15, 1);
	if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)){
		// press button 7
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7));
		return num_op[4];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)){
		// press button 8
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
		return num_op[5];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)){
		// press button 9
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
		return num_op[6];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)){
		// press button 10
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10));
		return num_op[7];
	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_15, 1);
	if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)){
		// press button 7
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7));
		return num_op[8];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)){
		// press button 8
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
		return num_op[9];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)){
		// press button 9
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
		return num_op[10];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)){
		// press button 10
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10));
		return num_op[11];
	}

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 , 1);
	if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)){
		// press button 7
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7));
		return num_op[12];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8)){
		// press button 8
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_8));
		return num_op[13];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9)){
		// press button 9
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
		return num_op[14];
	}
	else if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10)){
		// press button 10
		while(!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10));
		return num_op[15];
	}
	return 0;
}
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();
  LCD_Clear();
  char array[30]; // store all data when pressing except "del" button
  int t = -1; // Current order in array[30]
  int x = -1; // Location on LCD
  char op[7];   // store all operators
  double num[8]; // store all numbers
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		char k = Key_Scan();
		if(k){
			if (k == 'd'){
				// if press "del" button
				if(x>=0){
				  char string[2] = {' ', '\0'};
				  LCD_Location(x, 0);
				  x-=1;
				  LCD_Write_String(string); // remove number or operator on LCD
				  array[t] = '\0';
				  t-=1;
				}
			}
			else if(k == '='){
				// if press "=" button
				char string[2] = {' ', '\0'};
				for (int clr_2=0; clr_2<16; clr_2++){
				  LCD_Location(clr_2, 1);
				  HAL_Delay(5);
				  LCD_Write_String(string); // remove all data on LCD
				}
				for (int j=0; j<8; j++){
					num[j]='\0'; // if j < 8 => num[0=>7] = null character
					if (j<7){
					op[j]='\0'; // if j < 7 => num[0=>6] =  null character
					}
				}
				double sum=0;
				int op_sin=0; // number of operator
				for (int i=0; i<t+1; i++){
					if (array[i]>='0' && array[i]<='9'){
						sum = sum*10 + (array[i] - '0');
						num[op_sin]=sum;
					}
					else if(array[i]=='+' || array[i]=='-' || array[i]=='*' || array[i]=='/'){
						op[op_sin]=array[i];
						op_sin+=1;
						sum=0;
					}
				}
				//Perform multiplication, division, and subtraction operations first
				//and then convert them into addition operations.
				for (int i=0; i<op_sin; i++){
					if(op[i]=='*'){
						num[i+1]=num[i] * num[i+1];
						num[i]=0;
						op[i]='+';
					}
					else if(op[i]=='/'){
						num[i+1]=num[i] / num[i+1];
						num[i]=0;
						op[i]='+';
					}
					else if (op[i]=='-'){
						num[i+1]=-num[i+1];
						op[i]='+';
					}
				}
				for (int i=0; i<op_sin; i++){
					num[i+1]=num[i] + num[i+1];
				}
				sum = num[op_sin];  // result
				LCD_Location(0,1);
				LCD_Write_Number(sum);
			}
			else{
				t+=1;
				array[t]=k;
				char string[2] = {k,'\0'};
				x+=1;
				LCD_Location(x,0);
				LCD_Write_String(string); // display number or operator on LCD
				HAL_Delay(50);
			}
		}
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA7 PA8 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
