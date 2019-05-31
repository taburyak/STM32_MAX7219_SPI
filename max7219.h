/*
 * max7219.h
 *
 *  Created on: May 11, 2019
 *      Author: tabur
 */

#ifndef MAX7219_H_
#define MAX7219_H_

#include "main.h"
#include "stdbool.h"

#define NUMBER_OF_DIGITS	8
#define SPI_PORT			hspi1

extern SPI_HandleTypeDef 	SPI_PORT;

typedef enum {
	REG_NO_OP 			= 0x00,
	REG_DIGIT_0 		= 0x01,
	REG_DIGIT_1 		= 0x02,
	REG_DIGIT_2 		= 0x03,
	REG_DIGIT_3 		= 0x04,
	REG_DIGIT_4 		= 0x05,
	REG_DIGIT_5 		= 0x06,
	REG_DIGIT_6 		= 0x07,
	REG_DIGIT_7 		= 0x08,
	REG_DECODE_MODE 	= 0x09,
	REG_INTENSITY 		= 0x0A,
	REG_SCAN_LIMIT 		= 0x0B,
	REG_SHUTDOWN 		= 0x0C,
	REG_DISPLAY_TEST 	= 0x0F,
} MAX7219_REGISTERS;

typedef enum {
	DIGIT_1 = 1, DIGIT_2 = 2, DIGIT_3 = 3, DIGIT_4 = 4,
	DIGIT_5 = 5, DIGIT_6 = 6, DIGIT_7 = 7, DIGIT_8 = 8
} MAX7219_Digits;

typedef enum {
	NUM_0		= 0x00,
	NUM_1		= 0x01,
	NUM_2		= 0x02,
	NUM_3		= 0x03,
	NUM_4		= 0x04,
	NUM_5		= 0x05,
	NUM_6		= 0x06,
	NUM_7		= 0x07,
	NUM_8		= 0x08,
	NUM_9		= 0x09,
	MINUS		= 0x0A,
	LETTER_E	= 0x0B,
	LETTER_H	= 0x0C,
	LETTER_L	= 0x0D,
	LETTER_P	= 0x0E,
	BLANK		= 0x0F
}MAX7219_Numeric;

void max7219_Init(uint8_t intensivity);
void max7219_SetIntensivity(uint8_t intensivity);
void max7219_Clean(void);
void max7219_SendData(uint8_t addr, uint8_t data);
void max7219_Turn_On(void);
void max7219_Turn_Off(void);
void max7219_Decode_On(void);
void max7219_Decode_Off(void);
void max7219_PrintDigit(MAX7219_Digits position, MAX7219_Numeric numeric, bool point);
MAX7219_Digits max7219_PrintItos(MAX7219_Digits position, int value);
MAX7219_Digits max7219_PrintNtos(MAX7219_Digits position, uint32_t value, uint8_t n);
MAX7219_Digits max7219_PrintFtos(MAX7219_Digits position, float value, uint8_t n);

#endif /* MAX7219_H_ */
