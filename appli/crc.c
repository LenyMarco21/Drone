/*
 * crc.c
 *
 *  Created on: May 28, 2024
 *      Author: l.marcolini
 */


/* Includes =============================================================== */

#include "crc.h"

/* Define ================================================================= */

/* Enumeration ============================================================*/

/* Structure ============================================================== */

/* Static variables ======================================================= */

static CRC_HandleTypeDef hcrc = {0};

/* Static function prototype =============================================== */

/* Function  ============================================================== */

/**
 * @func 	void CRC_init(void)
 * @brief	Initialise le module CRC
 **/
void CRC_init(void)
{
	hcrc.Instance = CRC;

	if (HAL_CRC_Init(&hcrc) != HAL_OK)
	{
		// Handle errors ...
	}
}


/**
 * @func 	bool_e CRC_compare_8b(uint32_t crc_code, uint8_t* buff, uint16_t length)
 * @brief	Vérifie que le code crc, correspond bien au buffer 8 bits spécifié
 * @details Il s'agit d'une adaptation pour tableaux 8 bits de HAL_CRC_Calculate
 * 			qui nativement ne supporte que les tableaux d'entiers 32 bits.
 *
 * @param	crc_code : code à comparer avec le buffer spécifié
 * @param	buff* : buffer contenant les octets utiles
 * @param	length : taille du buffer
 **/
bool_e CRC_compare_8b(uint32_t crc_code, uint8_t* buff, uint16_t length)
{
	uint32_t index = 0U;

	__HAL_LOCK(&hcrc);

	hcrc.State = HAL_CRC_STATE_BUSY;

	__HAL_CRC_DR_RESET(&hcrc);

	for(index = 0U; index < length; index++)
	{
		hcrc.Instance->DR = (uint32_t)buff[index];
	}

	hcrc.State = HAL_CRC_STATE_READY;

	__HAL_UNLOCK(&hcrc);

	return ((hcrc.Instance->DR & 0xFFFF) == crc_code);
}


/**
 * @func 	void HAL_CRC_MspInit(CRC_HandleTypeDef* crcHandle)
 * @brief	Permet de démarrer le module CRC
 * @param	crcHandle : gestionnaire de module CRC
 **/
void HAL_CRC_MspInit(CRC_HandleTypeDef* crcHandle)
{

  if(crcHandle->Instance==CRC)
  {
    __HAL_RCC_CRC_CLK_ENABLE();
  }
}


/**
 * @func 	void HAL_CRC_MspDeInit(CRC_HandleTypeDef* crcHandle)
 * @brief	Permet d'éteindre le module CRC
 * @param	crcHandle : gestionnaire de module CRC
 **/
void HAL_CRC_MspDeInit(CRC_HandleTypeDef* crcHandle)
{

  if(crcHandle->Instance==CRC)
  {
    __HAL_RCC_CRC_CLK_DISABLE();
  }
}
