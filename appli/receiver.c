/*
 * rf_receive.c
 *
 *  Created on: May 22, 2024
 *      Author: l.marcolini
 */


/* Includes =============================================================== */

#include <assert.h>
#include "receiver.h"
#include "crc.h"

/* Define ================================================================= */

// Constantes
#define DATA_FRAME_SIZE			6

// Macros
#define DISABLE_UART_IRQ()		(NVIC_DisableIRQ(nvic_irq_array[uart_channel]))
#define ENABLE_UART_IRQ()		(NVIC_EnableIRQ(nvic_irq_array[uart_channel]))

// #define RF_RECEIVE_DEBUG
#ifdef RECEIVER_DEBUG
static volatile uint32_t time_watch[30] = {0};
static volatile uint8_t char_watch[30] = {0};
static volatile uint32_t indice = 0;
#endif

/* Enumeration ============================================================*/

/* Structure ============================================================== */

// Format de trame de données reçue sur le bus de communication
typedef union
{
	uint8_t bytes[DATA_FRAME_SIZE];

	struct __attribute__((packed))
	{
		int8_t x;
		int8_t y;
		int8_t z;
		uint16_t crc16;
		uint8_t end_char;
	}
	fields;
}
u_data_frame;

// L'instruction ci-dessous teste que la taille du buffer équivaut bien à la taille attendue des champs concaténés
static_assert(offsetof(u_data_frame, fields.end_char) != sizeof(((u_data_frame){0}).bytes), "Alignement incorrect dans u_data_frame");

/* Static variables ======================================================= */

// Flag d'initialisation du module
static bool_e init_flag = FALSE;

// Canal UART utilisé
static uart_id_e uart_channel;

// Delai de timeout en millisecondes
static volatile uint32_t timeout_delay_ms;

// Flag indiquant que de nouvelles données sont disponibles
static volatile bool_e new_data_available = FALSE;

// Flag indiquant que des données non conformes ont été détectées
static volatile bool_e corrupted_data_detected = FALSE;

// Union contenant les champs de data valides
static volatile u_data_frame valid_data = {0};

// Table de correspondance d'identifiants NVIC par UART.
static const IRQn_Type nvic_irq_array[UART_ID_NB] = {USART1_IRQn, USART2_IRQn, USART3_IRQn};

/* Static function prototype =============================================== */

static void RECEIVER_callback_routine();

/* Function  ============================================================== */

/**
 * @func 	void RECEIVER_init(uart_id_e uart_id, uint32_t baudrate, uint32_t delay_ms)
 * @brief	Méthode permettant d'initialiser la réception de trame sur le canal UART spécifié
 * @param	uart_id : canal UART sur lequel scruter la réception de données
 *
 **/
void RECEIVER_init(uart_id_e uart_id, uint32_t baudrate, uint32_t delay_ms)
{
	/* Début protection contre les préemptions non atomiques */
	DISABLE_UART_IRQ();

	// Initialisation du CRC hardware
	CRC_init();

	// Configuration du module UART
	timeout_delay_ms = delay_ms;
	uart_channel = uart_id;
	UART_init(uart_channel, baudrate);
	UART_set_callback(uart_channel, &RECEIVER_callback_routine);

	// Flag d'initialisation clear
	init_flag = FALSE;

	// Tir à blanc pour réinitialiser la routine
	RECEIVER_callback_routine();

	// Flag d'initialisation levé
	init_flag = TRUE;

	/* Fin protection contre les préemptions non atomiques */
	ENABLE_UART_IRQ();
}


/**
 * @func 	bool_e RECEIVER_data_available(void)
 * @brief	Indique si de nouvelles données valides ont été obtenues
 * @return 	vrai ou faux
 **/
bool_e RECEIVER_data_available(void)
{
	bool_e ret = new_data_available;
	new_data_available = FALSE;

	return ret;
}


/**
 * @func 	bool_e RECEIVER_data_error(void)
 * @brief	Indique qu'une trame de données érronées a été détectée
 * @return 	vrai ou faux
 **/
bool_e RECEIVER_data_error(void)
{
	bool_e ret = corrupted_data_detected;
	corrupted_data_detected = FALSE;

	return ret;
}


/**
 * @func 	void RECEIVER_fetch_data(st_receiver_data *data)
 * @brief	Renvoie les données valides obtenues par le recepteur RF
 * @param	*data : union u_data_frame contenant les datas utiles
 **/
void RECEIVER_fetch_data(st_receiver_data *data)
{
	/* Début protection contre les préemptions non atomiques */
	DISABLE_UART_IRQ();

	// Copie des valeurs dans le buffer de retour
	data->x = valid_data.fields.x;
	data->y = valid_data.fields.y;
	data->z = valid_data.fields.z;

	// Flag de réception clear
	new_data_available = FALSE;

	/* Fin protection contre les préemptions non atomiques */
	ENABLE_UART_IRQ();
}


/**
 * @func 	static void RECEIVER_callback_routine()
 * @brief	Routine appelée périodiquement effectuant une scrutation sur le canal UART paramétré
 **/
static void RECEIVER_callback_routine()
{
	static volatile bool_e transfer_reset = TRUE;
	static volatile uint32_t previous_time = 0;
	static volatile uint32_t bytes_received = 0;
	static volatile u_data_frame buff = {0};

	// Si le module n'est pas initialisé -> sortie
	if (init_flag == FALSE)
	{
		transfer_reset = TRUE;
		return;
	}

	// Si le délai de timeout est dépassé, on initialise un nouveau transfert
	if ((HAL_GetTick() - previous_time) >= timeout_delay_ms)
	{
		transfer_reset = TRUE;
	}

	// Si l'initialisation d'un transfert est demandée
	if (transfer_reset)
	{
		bytes_received = 0;
		transfer_reset = FALSE;
	}

	// Récupère la data disponible sur l'UART
	if (UART_data_ready(uart_channel) && bytes_received < DATA_FRAME_SIZE)
	{
		buff.bytes[bytes_received] = UART_get_next_byte(uart_channel);
		previous_time = HAL_GetTick();

#ifdef RECEIVER_DEBUG
		if (indice < 30){
			time_watch[indice] = HAL_GetTick();
			char_watch[indice] = buff.bytes[bytes_received];
			indice++;
		}
#endif

		bytes_received++;
	}

	// Si le nombre d'octets nécessaire est atteint : étape suivante
	if (bytes_received == DATA_FRAME_SIZE)
	{
		// On vérifie que le CRC-16 correspond bien
		if (CRC_compare_8b(buff.fields.crc16, buff.bytes, 3))
		{
			// Copie les valeurs dans le buffer publique
			valid_data.fields.x = buff.fields.x;
			valid_data.fields.y = buff.fields.y;
			valid_data.fields.z = buff.fields.z;

			// Lève le flag indiquant que de nouvelles données sont disponibles
			new_data_available = TRUE;
		}
		else
		{
			corrupted_data_detected = TRUE;
		}

		transfer_reset = TRUE;
	}
}
