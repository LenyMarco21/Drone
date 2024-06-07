/*
 * crc.h
 *
 *  Created on: May 28, 2024
 *      Author: l.marcolini
 */

#ifndef CRC_H_
#define CRC_H_

/* Includes =============================================================== */

#include "config.h"
#include "macro_types.h"

/* Defines ================================================================ */

/* Enumerations ============================================================*/

/* Structures ============================================================= */

/* External function prototypes =========================================== */

void CRC_init(void);

bool_e CRC_compare_8b(uint32_t crc_code, uint8_t* buff, uint16_t length);

#endif /* CRC_H_ */
