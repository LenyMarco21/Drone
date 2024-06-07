/*
 * rf_receive.h
 *
 *  Created on: May 22, 2024
 *      Author: l.marcolini
 */

#ifndef RECEIVER_H_
#define RECEIVER_H_

/* Includes =============================================================== */

#include "config.h"
#include "stm32f1_uart.h"
#include "macro_types.h"

/* Defines ================================================================ */

/* Enumerations ============================================================*/

/* Structures ============================================================= */

typedef struct
{
	int16_t x;
	int16_t y;
	int16_t z;
}
st_receiver_data;

/* External function prototypes =========================================== */

/**
 * @func 	void RECEIVER_init(uart_id_e uart_id, uint32_t baudrate, uint32_t delay_ms)
 * @brief	Méthode permettant d'initialiser la réception de trame sur le canal UART spécifié
 * @param	uart_id : canal UART sur lequel scruter la réception de données
 */
extern void RECEIVER_init(uart_id_e uart_id, uint32_t baudrate, uint32_t delay_ms);

extern void RECEIVER_fetch_data(st_receiver_data *data);

extern bool_e RECEIVER_data_available(void);

extern bool_e RECEIVER_data_error(void);

#endif /* RECEIVER_H_ */
