/*
 * motor.c
 *
 *      Author: l.marcolini
 */


/* Includes =============================================================== */

#include "motor.h"
#include "stm32f1_timer.h"

/* Define ================================================================= */

/* Enumeration ============================================================ */

/* Structure ============================================================== */

/* Static variables ======================================================= */

/* Static function prototype ============================================== */

/* Function  ============================================================== */

void MOTOR_init()
{
	MOTOR_add(GPIOA, GPIO_PIN_8, GPIOB, GPIO_PIN_13);
	MOTOR_add(GPIOA, GPIO_PIN_9, GPIOB, GPIO_PIN_14);
	MOTOR_add(GPIOA, GPIO_PIN_10, GPIOB, GPIO_PIN_15);
	MOTOR_add(GPIOA, GPIO_PIN_11, GPIOB, GPIO_PIN_11);
	MOTOR_add(GPIOA, GPIO_PIN_6, GPIOB, GPIO_PIN_15);
	MOTOR_add(GPIOA, GPIO_PIN_7, GPIOB, GPIO_PIN_11);

	MOTOR_drive(MOTOR_ID_0, 20);
	MOTOR_drive(MOTOR_ID_1, 20);
	MOTOR_drive(MOTOR_ID_2, 20);
	MOTOR_drive(MOTOR_ID_3, 20);
	MOTOR_drive(MOTOR_ID_4, 20);
	MOTOR_drive(MOTOR_ID_5, 20);
}


void MOTOR_drive(motor_id_e motor_id, uint8_t setpoint)
{
	if (motor_id > MOTOR_ID_3)
	{
		MOTOR_set_duty(motor_id, 100 - setpoint);
	}
	else
	{
		MOTOR_set_duty(motor_id, setpoint);
	}
}
