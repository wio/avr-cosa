Che Cosa?
=========

Cosa is an object-oriented platform for Arduino that supports an
event-driven programming paradigm with simple finite state
machines. It contains a rich set of classes to support rapid
prototyping of Internet-of-Things devices. Cosa supports the following
AVR/Atmega328P internal hardware modules; all pin modes, interrupt
pins, PWM, Watchdog, Timer-0, UART (transmit), SPI and TWI.

Cosa also contains a data streaming format (Ciao) for encoding of
C/C++ language data types such as strings, integer and floating
pointer numbers into a binary format. It may be used for a number of
applications; tracing, remote procedure calls, data exchange between
Arduino devices, etc. The format allows user data types to be defined
and values exchanged without additional encoding. The stream header
itself is a pre-defined serializable data type. Ciao is used to define
an Arduino monitoring and control language (Cosa fai) which has much
in common with Firmata. See
[CIAO.txt](https://github.com/mikaelpatel/Cosa/blob/master/CIAO.txt)
for more details and the example code (examples/Ciao). 

The primary programming paradigm is object-oriented and
state-machine/event driven. There is a large number of device drivers
available for SPI, TWI/I2C and 1-Wire. A strict directory 
structure is used to organize the Cosa/driver source
code. Sub-directories are used for each driver type. 

Cosa uses the Arduino IDE and build system. Cosa classes are included
with prefix, e.g. "Cosa/FileName.hh". It is possible to use both
Arduino and Cosa functions together, though in some cases the Cosa
objects may become inconsistent. 

To improve debugging and testing there is trace/syslog style support. 
The IOStream class allows output to both serial communication (UART) 
and small TFT displays (such as the SR7735R). The drawing Canvas class
supports basic drawing operation and scripting to reduce program
memory footprint. The Canvas class also supports drawing of icons and
multiple fonts. 

The goal of this project is to provide an efficient programming
platform for rapid prototyping of "Internet-of-things"-devices. 
Unfortunately Cosa is not a beginners entry level programming
platform, though following some of the design patterns in Cosa will
help beginners build more complex small scale embedded systems with
richer concurrency and low power consumption.  

News
----
2013-01-23 Arduino Mega 2560 initial port.  
2013-01-25 UTFT Font support added.  
2013-01-29 Proto-threads implemented. Draw/fill round rectangle added
to Canvas.  
2013-02-01 Adding doxygen generated documentation (doc.zip).  

Install
-------

To install download and move the Cosa directory to the Arduino cores
directory within arduino itself, i.e.,
your-arduino-install-directory/hardware/arduino/cores/arduino. The
examples should be moved to your Arduino sketchbook directory. 

The programmers application interface documentation is available as
HTML in the file doc.zip. Uncompress this file and navigate your
browser to the index file. The documentation contains a full
hyperlinked description of all functions in Cosa together with UML
graphs of the class hierarchy. 

Drivers
-------

1. DS18B20 Programmable Resolution 1-Wire Digital Thermometer.
2. AT24CXX Serial EEPROM.
3. DS1307 Realtime clock with RAM.
4. PCF8591 2-Wire 8-bit A/D and D/A converter.
5. ADXL345 Digital Accelerometer.
6. nRF24L01 Single Chip 2.4GHz Transceiver. 
7. DHT11 Humidity & Temperature Sensor.
8. HC-SR04/US-020 Ultrasonic range module.
9. ST7735R, 262K Color Single-Chip TFT Controller.
10. Slave device support for SPI, TWI and OWI.

The reference documentation for each device driver hardware module may
be found in the Cosa/references directory.  

References
----------

1. D.tools, http://hci.stanford.edu/research/dtools/
2. Processing, http://processing.org/
3. Wiring, http://wiring.org.co/
4. Arduino, http://www.arduino.cc/
5. Firmata, http://www.firmata.org/wiki/Main_Page
6. LilyPad, http://web.media.mit.edu/~leah/LilyPad/
7. Jeelabs, http://jeelabs.org/
8. Quantum Leaps, http://www.state-machine.com/
9. Concurrency.cc, http://concurrency.cc/

Naming
------

* "Cosa"; noun thing, matter; pronoun; what?, what!. 
* "Che cosa"; pronoun; what. 
* "Ciao"; interjection hello!, goodbye!. 
* "Cosa fai"; what do you do?

Note
----

Atmega328P and Atmega2560 based Arduino boards (Uno, Mini, Nano,
LilyPad, Mega, etc) are supported. Timers (1-n), EEPROM, UART
(receiver) are not directly supported but planned. Arduino
and AVR lib functions may be used together with Cosa.



