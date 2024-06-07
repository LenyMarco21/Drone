/**
  ******************************************************************************
  * @file    main.c
  * @author  Nirgal
  * @date    03-July-2019
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "macro_types.h"
#include "assert.h"
#include "systick.h"
#include "motor.h"
#include "receiver.h"


void writeLED(bool_e b)
{
	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, b);
}

bool_e readButton(void)
{
	return !HAL_GPIO_ReadPin(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN);
}


static volatile uint32_t t = 0;
void process_ms(void)
{
	if(t)
		t--;
}

void set_drone_position(st_receiver_data *data);

int main(void)
{
	//Initialisation de la couche logicielle HAL (Hardware Abstraction Layer)
	//Cette ligne doit rester la première étape de la fonction main().
	HAL_Init();

	//Initialisation du port de la led Verte (carte Nucleo)
	BSP_GPIO_PinCfg(LED_GREEN_GPIO, LED_GREEN_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);

	//Initialisation du port du bouton bleu (carte Nucleo)
	BSP_GPIO_PinCfg(BLUE_BUTTON_GPIO, BLUE_BUTTON_PIN, GPIO_MODE_INPUT,GPIO_PULLUP,GPIO_SPEED_FREQ_HIGH);

	//On ajoute la fonction process_ms à la liste des fonctions appelées automatiquement chaque ms par la routine d'interruption du périphérique SYSTICK
	Systick_add_callback_function(&process_ms);

	// Initialise les moteurs
	MOTOR_init();

	HAL_GPIO_WritePin(LED_GREEN_GPIO, LED_GREEN_PIN, 0);

	//Initialisation de l'UART2 à la vitesse de 115200 bauds/secondes (92kbits/s) PA2 : Tx  | PA3 : Rx.
	//Attention, les pins PA2 et PA3 ne sont pas reliées jusqu'au connecteur de la Nucleo.
	//Ces broches sont redirigées vers la sonde de débogage, la liaison UART étant ensuite encapsulée sur l'USB vers le PC de développement.
	RECEIVER_init(UART2_ID, 4000, 6);

	while(1)	//boucle de tâche de fond
	{
		st_receiver_data data = {0};

		if(!t)
		{
			if (RECEIVER_data_available())
			{
				RECEIVER_fetch_data(&data);

				set_drone_position(&data);
			}
		}
	}
}

void set_drone_position(st_receiver_data *data)
{
	if (data->x > 0 && data->y > 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 10);
		MOTOR_drive(MOTOR_ID_1, data->z + 10);
		MOTOR_drive(MOTOR_ID_2, data->z + 10);
		MOTOR_drive(MOTOR_ID_3, data->z + 75);
		MOTOR_drive(MOTOR_ID_4, data->z + 10);
		MOTOR_drive(MOTOR_ID_5, data->z + 75);
	}

	else if (data->x < 0 && data->y > 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 10);
		MOTOR_drive(MOTOR_ID_1, data->z + 10);
		MOTOR_drive(MOTOR_ID_2, data->z + 10);
		MOTOR_drive(MOTOR_ID_3, data->z + 10);
		MOTOR_drive(MOTOR_ID_4, data->z + 75);
		MOTOR_drive(MOTOR_ID_5, data->z + 75);
	}
	else if (data->x > 0 && data->y < 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 75);
		MOTOR_drive(MOTOR_ID_1, data->z + 10);
		MOTOR_drive(MOTOR_ID_2, data->z + 75);
		MOTOR_drive(MOTOR_ID_3, data->z + 10);
		MOTOR_drive(MOTOR_ID_4, data->z + 10);
		MOTOR_drive(MOTOR_ID_5, data->z + 10);
	}
	else if (data->x < 0 && data->y < 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 75);
		MOTOR_drive(MOTOR_ID_1, data->z + 75);
		MOTOR_drive(MOTOR_ID_2, data->z + 10);
		MOTOR_drive(MOTOR_ID_3, data->z + 10);
		MOTOR_drive(MOTOR_ID_4, data->z + 10);
		MOTOR_drive(MOTOR_ID_5, data->z + 10);
	}
	else if (data->x > 0 && data->y == 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 10);
		MOTOR_drive(MOTOR_ID_1, data->z + 10);
		MOTOR_drive(MOTOR_ID_2, data->z + 75);
		MOTOR_drive(MOTOR_ID_3, data->z + 75);
		MOTOR_drive(MOTOR_ID_4, data->z + 10);
		MOTOR_drive(MOTOR_ID_5, data->z + 10);
	}
	else if (data->x < 0 && data->y == 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 10);
		MOTOR_drive(MOTOR_ID_1, data->z + 75);
		MOTOR_drive(MOTOR_ID_2, data->z + 10);
		MOTOR_drive(MOTOR_ID_3, data->z + 10);
		MOTOR_drive(MOTOR_ID_4, data->z + 75);
		MOTOR_drive(MOTOR_ID_5, data->z + 10);
	}
	else if (data->x == 0 && data->y > 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 10);
		MOTOR_drive(MOTOR_ID_1, data->z + 10);
		MOTOR_drive(MOTOR_ID_2, data->z + 10);
		MOTOR_drive(MOTOR_ID_3, data->z + 75);
		MOTOR_drive(MOTOR_ID_4, data->z + 75);
		MOTOR_drive(MOTOR_ID_5, data->z + 75);
	}
	else if (data->x == 0 && data->y < 0)
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 75);
		MOTOR_drive(MOTOR_ID_1, data->z + 75);
		MOTOR_drive(MOTOR_ID_2, data->z + 75);
		MOTOR_drive(MOTOR_ID_3, data->z + 10);
		MOTOR_drive(MOTOR_ID_4, data->z + 10);
		MOTOR_drive(MOTOR_ID_5, data->z + 10);
	}
	else
	{
		MOTOR_drive(MOTOR_ID_0, data->z + 0);
		MOTOR_drive(MOTOR_ID_1, data->z + 0);
		MOTOR_drive(MOTOR_ID_2, data->z + 0);
		MOTOR_drive(MOTOR_ID_3, data->z + 0);
		MOTOR_drive(MOTOR_ID_4, data->z + 0);
		MOTOR_drive(MOTOR_ID_5, data->z + 0);
	}
}
