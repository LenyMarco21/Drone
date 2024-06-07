/*
 * motor.h
 *
 *  Created on: May 15, 2024
 *      Author: l.marcolini
 */

#ifndef MOTOR_H_
#define MOTOR_H_

/* Includes =============================================================== */

#include "config.h"
#include "stm32f1_motorDC.h"
#include "macro_types.h"

/* Defines ================================================================ */

/* Enumerations ============================================================*/

/* Structures ============================================================= */

/* External function prototypes =========================================== */

extern void MOTOR_init();

extern void MOTOR_drive(motor_id_e motor_id, uint8_t setpoint);



#endif /* MOTOR_H_ */
