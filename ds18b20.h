/*
	ds18b20 lib

	this project is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	this software is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	You should have received a copy of the GNU General Public License.
	If not, see <http://www.gnu.org/licenses/>.

	Author: Dmitry G. Shchelkunov
	Email: d.shelkunov@specsist.ru
	Github: https://github.com/7Upers

	Special thanks to:
	* Davide Gironi, original implementation 2012
*/

#ifndef DS18B20_H_
#define DS18B20_H_

#include <avr/io.h>

//setup connection
#define DS18B20_PORT PORTB
#define DS18B20_DDR DDRB
#define DS18B20_PIN PINB
#define DS18B20_DQ PB0

//commands
#define DS18B20_CMD_CONVERTTEMP 0x44
#define DS18B20_CMD_RSCRATCHPAD 0xbe
#define DS18B20_CMD_WSCRATCHPAD 0x4e
#define DS18B20_CMD_CPYSCRATCHPAD 0x48
#define DS18B20_CMD_RECEEPROM 0xb8
#define DS18B20_CMD_RPWRSUPPLY 0xb4
#define DS18B20_CMD_SEARCHROM 0xf0
#define DS18B20_CMD_READROM 0x33
#define DS18B20_CMD_MATCHROM 0x55
#define DS18B20_CMD_SKIPROM 0xcc
#define DS18B20_CMD_ALARMSEARCH 0xec

//stop any interrupt on read
#define DS18B20_STOPINTERRUPTONREAD 1

//functions
uint8_t crc8(uint8_t *addr, uint8_t len);
extern double ds18b20_getsometemp();
uint8_t ds18b20_startconvert(uint8_t *addr);
extern double ds18b20_gettemp(uint8_t *addr);
void ds18b20_getaddr(uint8_t *sn);
void ds18b20_search(uint8_t sensors[][8]);

#endif
