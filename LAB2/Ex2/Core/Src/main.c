/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(uint16_t Pin1, uint16_t Pin2, uint16_t Pin3, uint16_t Pin4, uint16_t Pin5, uint16_t Pin6, uint16_t Pin7,
				 GPIO_TypeDef* Port1, GPIO_TypeDef* Port2, GPIO_TypeDef* Port3, GPIO_TypeDef* Port4, GPIO_TypeDef* Port5, GPIO_TypeDef* Port6, GPIO_TypeDef* Port7,
				 int num) {
	switch(num) {
	case 0: //Number 0 is 0000001
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;

	case 1: //Number 1 is 1001111
		HAL_GPIO_WritePin(Port1, Pin1, SET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;

	case 2: //Number 2 is 0010010
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, SET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 3: //Number 3 is 0000110
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 4: //Number 4 is 1001100
		HAL_GPIO_WritePin(Port1, Pin1, SET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 5: //Number 5 is 0100100
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, SET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 6: //Number 6 is 0100000
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, SET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 7: //Number 7 is 0001111
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, SET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, SET);
		HAL_GPIO_WritePin(Port7, Pin7, SET);
		break;

	case 8: //Number 8 is 0000000
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, RESET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	case 9: //Number 9 is 0000100
		HAL_GPIO_WritePin(Port1, Pin1, RESET);
		HAL_GPIO_WritePin(Port2, Pin2, RESET);
		HAL_GPIO_WritePin(Port3, Pin3, RESET);
		HAL_GPIO_WritePin(Port4, Pin4, RESET);
		HAL_GPIO_WritePin(Port5, Pin5, SET);
		HAL_GPIO_WritePin(Port6, Pin6, RESET);
		HAL_GPIO_WritePin(Port7, Pin7, RESET);
		break;

	default: break;
	}
}
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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_RED_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|DOT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_RED_Pin EN0_Pin EN1_Pin EN2_Pin
                           EN3_Pin */
  GPIO_InitStruct.Pin = LED_RED_Pin|EN0_Pin|EN1_Pin|EN2_Pin
                          |EN3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin DOT_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|DOT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
int counter1 = 50; //LED 7SEG counter
int counter2 = 200; //LED RED1 counter
int counter3 = 100; //counter of two LEDs display the colon

int status = 0; //LED 7SEG status
/*
 * status = 0: LED SEG1 display
 * status = 1: LED SEG2 display
 * status = 2: LED SEG3 display
 * status = 3: LED SEG4 display
 *
 */


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (status == 0) //LEG SEG1 is displaying
	{
		display7SEG(a_Pin, b_Pin, c_Pin, d_Pin, e_Pin, f_Pin, g_Pin,
				    a_GPIO_Port, b_GPIO_Port, c_GPIO_Port, d_GPIO_Port, e_GPIO_Port, f_GPIO_Port, g_GPIO_Port,
					1);

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

	}
	else if (status == 1) //LEG SEG2 is displaying
	{
		display7SEG(a_Pin, b_Pin, c_Pin, d_Pin, e_Pin, f_Pin, g_Pin,
				    a_GPIO_Port, b_GPIO_Port, c_GPIO_Port, d_GPIO_Port, e_GPIO_Port, f_GPIO_Port, g_GPIO_Port,
					2);

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

	}
	else if (status == 2) //LED SEG3 is displaying
	{
		display7SEG(a_Pin, b_Pin, c_Pin, d_Pin, e_Pin, f_Pin, g_Pin,
				    a_GPIO_Port, b_GPIO_Port, c_GPIO_Port, d_GPIO_Port, e_GPIO_Port, f_GPIO_Port, g_GPIO_Port,
					3);

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);

	}
	else if (status == 3) //LED SEG3 is displaying
	{
		display7SEG(a_Pin, b_Pin, c_Pin, d_Pin, e_Pin, f_Pin, g_Pin,
				    a_GPIO_Port, b_GPIO_Port, c_GPIO_Port, d_GPIO_Port, e_GPIO_Port, f_GPIO_Port, g_GPIO_Port,
					0);

		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);

	}

	if (counter2 <= 0) //switch LED RED every second
	{
		HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
		counter2 = 200; //reset counter2
	}

	if (counter3 <= 0) //switch LED RED every second
	{
		HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
		counter3 = 100; //reset counter3
	}

	if (htim -> Instance == TIM2) {
		counter1--;
		counter2--;
		counter3--;
	}

	if (counter1 <= 0) {
		switch(status) {
			case 0: status = 1; break; //LEG SEG1 is displaying -> switch to LED SEG2
			case 1: status = 2; break; //LEG SEG2 is displaying -> switch to LED SEG3
			case 2: status = 3; break; //LEG SEG3 is displaying -> switch to LED SEG4
			case 3: status = 0; break; //LEG SEG4 is displaying -> switch to LED SEG1
			default: break;
		}
		counter1 = 50; //reset counter1
	}
}
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
