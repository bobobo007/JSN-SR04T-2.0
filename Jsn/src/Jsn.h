/**
 * @author  Bohumir Coufal
 * @email   bohumir.coufal@gmail.com
 * @version v1.0
 * @ide     TrueSTUDIO
 * @license MIT
 * @brief   Library for communication with JSN-SR07T-2.0 ultrasonic sensor
 *
\verbatim
   ----------------------------------------------------------------------
    Copyright (c) 2016 Bohumir Coufal

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without restriction,
    including without limitation the rights to use, copy, modify, merge,
    publish, distribute, sublicense, and/or sell copies of the Software,
    and to permit persons to whom the Software is furnished to do so,
    subject to the following conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
    AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
   ----------------------------------------------------------------------
\endverbatim
*/
/**
 * Befor conect the JSN modul, please configure mode2 or mode3
 * Resistor 47k on position R27. JSN modul send every 100ms
 * a information about the distanc
 * Serial baud rate of the module: 9600, n, 8,1
 * See the Datasheed of JSN module
 */
#ifndef JSN_SR04T_2_0_H_
#define JSN_SR04T_2_0_H_

#if defined (ARDUINO) && ARDUINO >= 100
		#include <Arduino.h>
	#else
		#include <WProgram.h>
		#if defined (PARTICLE)
			#include <SparkIntervalTimer.h>
		#else
			#include <pins_arduino.h>
		#endif
	#endif

	#if defined (__AVR__)
		#include <avr/io.h>
		#include <avr/interrupt.h>
	#endif


//define Serial2
#define RXD2 16
#define TXD2 17

//define one of workings modes
#define mode1
//#define mode2

class jsn
{
	public:
	/**
	 * @brief	Function for setup Uart2
	 * @param	noting
	 * @retval	noting
	 */
	void setup_uart2();
	/**
	 * @brief	Function read distanc from modul JSN-SR04T-2.0
	 * @param	noting
	 * @retval	distanc
	 */
	int get_distanc();
};

#endif /* JSN_SR04T_2_0_H_ */
