/* 
  SPI.h - SPI library for esp8266

  Copyright (c) 2015 Hristo Gochkov. All rights reserved.
  This file is part of the esp8266 core for Arduino environment.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

// joba: SPI modes grabbed from a newer version of esp8266 header. Needed for compile, not tested
const uint8_t SPI_MODE0 = 0x00; ///<  CPOL: 0  CPHA: 0
const uint8_t SPI_MODE1 = 0x01; ///<  CPOL: 0  CPHA: 1
const uint8_t SPI_MODE2 = 0x10; ///<  CPOL: 1  CPHA: 0
const uint8_t SPI_MODE3 = 0x11; ///<  CPOL: 1  CPHA: 1

// joba fake class. CubeCell does not support settings (yet?)
class SPISettings
{
public:
  SPISettings(uint32_t , uint8_t , uint8_t ) {}
  SPISettings() {}
};

class SPIClass
{
private:
    int8_t _ss;
    bool _inTransaction;

public:
    SPIClass(uint8_t ss=-1);
    void begin(uint8_t ss=-1);
    void end();
    void beginTransaction(void);
    void beginTransaction(SPISettings ) { beginTransaction(); } // joba: fake settings for arduino libs using them
    void endTransaction(void);
    void transfer(uint8_t * data, uint32_t size);
    uint32_t transfer(uint32_t data);
  
    void transferBytes(uint8_t * data, uint8_t * out, uint32_t size);
};
typedef SPIClass SPIC;

extern SPIClass SPI;


