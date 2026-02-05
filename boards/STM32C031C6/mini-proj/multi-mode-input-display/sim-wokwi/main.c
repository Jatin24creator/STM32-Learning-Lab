/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// common anode configuration
#define D0S GPIO_PIN_6|GPIO_PIN_7 //SET == OFF
#define D0R GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5 //RESET == 1

#define D1S GPIO_PIN_0|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
#define D1R GPIO_PIN_1|GPIO_PIN_2

#define D2S GPIO_PIN_2|GPIO_PIN_5|GPIO_PIN_7
#define D2R GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_6

#define D3S GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7
#define D3R GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_6

#define D4S GPIO_PIN_0|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_7
#define D4R GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_5|GPIO_PIN_6

#define D5S GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_7
#define D5R GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6

#define D6S GPIO_PIN_1|GPIO_PIN_7
#define D6R GPIO_PIN_0|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6

#define D7S GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7
#define D7R GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2

#define D8S GPIO_PIN_7
#define D8R GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6

#define D9S GPIO_PIN_4|GPIO_PIN_7
#define D9R GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_5|GPIO_PIN_6


#define MODE_BUTTON 0
#define MODE_ADC 1
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int mode_flag = 0;
int digit_count = 0;
void mode_check_toggle(void){
	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)==(GPIO_PIN_RESET)){
		mode_flag = !mode_flag; //COMPARISON
		HAL_Delay(500);
		while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3)==(GPIO_PIN_RESET));
	}
}

void counter(int digit_count){
	//Turn off all the pins SET
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|
			GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, SET);
	switch(digit_count){
	case 0:
		HAL_GPIO_WritePin(GPIOB, D0S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D0R, RESET); //Turn the ones on
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, D1S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D1R, RESET); //Turn the ones on
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, D2S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D2R, RESET); //Turn the ones on
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, D3S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D3R, RESET); //Turn the ones on
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, D4S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D4R, RESET); //Turn the ones on
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, D5S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D5R, RESET); //Turn the ones on
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, D6S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D6R, RESET); //Turn the ones on
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, D7S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D7R, RESET); //Turn the ones on
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, D8S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D8R, RESET); //Turn the ones on
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, D9S, SET); // turn the not required ones off
		HAL_GPIO_WritePin(GPIOB, D9R, RESET); //Turn the ones on
		break;

	}

}

void adc(int adcResult){
	      if ((adcResult>=0)&&(adcResult<=409)){
			  counter(0);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		  }
		  else if((adcResult>=410)&&(adcResult<=819)){
			  counter(1);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		  }
		  else if((adcResult>=820)&&(adcResult<=1229)){
			  counter(2);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		  }
		  else if((adcResult>=1230)&&(adcResult<=1639)){
			  counter(3);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		  }
		  else if((adcResult>=1640)&&(adcResult<=2049)){
			  counter(4);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, SET);
		  }
		  else if((adcResult>=2050)&&(adcResult<=2459)){
			  counter(5);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		  }
		  else if((adcResult>=2460)&&(adcResult<=2869)){
			  counter(6);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		  }
		  else if((adcResult>=2870)&&(adcResult<=3279)){
			  counter(7);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		  }
		  else if((adcResult>=3280)&&(adcResult<=3689)){
			  counter(8);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		  }
		  else if((adcResult>=3690)&&(adcResult<=4095)){
			  counter(9);
			  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, RESET);
		  }

}
void button_counter(){
	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4)){
      HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6,SET);
		  //increment the digit count
		  digit_count++;

		  if (digit_count >9){ //resets to zero
			  digit_count = 0;
		  }
		  // display the digit via the function that displays the digit
		  counter(digit_count);
		  //simple debounce
		  HAL_Delay(500);
		  //wait until button is released

		  while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4));
	  }

	 //if button2 pressed ==0
	  else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5)){
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6,SET);
		  //then decrease by 1
		  digit_count--;
		  if(digit_count<0){
			  digit_count =9;
		  }
		  //display the digit
		  counter(digit_count);
		  //debounce
		  HAL_Delay(500);
		  // wait until button released

		  while(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5));

	  }
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,RESET);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	int adcResult;
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
  MX_ADC1_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  mode_check_toggle();
	  if(mode_flag == 0){
		  button_counter();
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, SET);
	  }else {
		  //ADC IS 12 BIT RESOLUTION SO MAX DIGITAL VALU IS 4096
		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, RESET);
		  HAL_ADC_Start(&hadc1); //USED TO START ADC OPERATION
		  HAL_ADC_PollForConversion(&hadc1, 100);
		  adcResult = HAL_ADC_GetValue(&hadc1);
		  HAL_ADC_Stop(&hadc1);
		  adc(adcResult);
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

  __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */

  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV2;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.ScanConvMode = ADC_SCAN_SEQ_FIXED;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  hadc1.Init.LowPowerAutoWait = DISABLE;
  hadc1.Init.LowPowerAutoPowerOff = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.Overrun = ADC_OVR_DATA_PRESERVED;
  hadc1.Init.SamplingTimeCommon1 = ADC_SAMPLETIME_1CYCLE_5;
  hadc1.Init.OversamplingMode = DISABLE;
  hadc1.Init.TriggerFrequencyMode = ADC_TRIGGER_FREQ_HIGH;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure Regular Channel
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

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
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA3 PA4 PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB2 PB3
                           PB4 PB5 PB6 PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
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
