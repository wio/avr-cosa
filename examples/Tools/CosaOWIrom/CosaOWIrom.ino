/**
 * @file CosaOWIrom.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2013-2015, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * @section Description
 * Tool to generate ROM definitions for connected 1-wire devices.
 *
 * This file is part of the Arduino Che Cosa project.
 */

#include <OWI.h>

#include "Cosa/Board.hh"
#include "Cosa/Trace.hh"
#include "Cosa/UART.hh"

// One-wire pin
#if !defined(BOARD_ATTINY)
OWI owi(Board::D7);
#else
OWI owi(Board::D1);
#endif

void setup()
{
  // Start trace output stream on the serial port
  uart.begin(9600);
  trace.begin(&uart, PSTR("// Generated by CosaOWIrom, rev. 1.0\n"));

  // List connected devices
  OWI::Driver dev(&owi);
  int8_t last = OWI::Driver::FIRST;
  uint8_t nr = 0;
  do {
    last = dev.search_rom(last);
    if (last == OWI::Driver::ERROR) break;
    trace << PSTR("static const uint8_t dev") << nr++ << PSTR("[] = {\n  ");
    uint8_t* rom = dev.rom();
    trace << hex << rom[0];
    for (uint8_t i = 1; i < OWI::ROM_MAX; i++) {
      trace << PSTR(", ");
      trace << hex << rom[i];
    }
    trace << PSTR("\n};\n\n");
  } while (last != OWI::Driver::LAST);
}

void loop()
{
}
