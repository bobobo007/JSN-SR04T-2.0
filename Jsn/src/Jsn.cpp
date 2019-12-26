/**
 * |----------------------------------------------------------------------
 * | Copyright (c) 2019 Bohumir Coufal
 * |
 * | Permission is hereby granted, free of charge, to any person
 * | obtaining a copy of this software and associated documentation
 * | files (the "Software"), to deal in the Software without restriction,
 * | including without limitation the rights to use, copy, modify, merge,
 * | publish, distribute, sublicense, and/or sell copies of the Software,
 * | and to permit persons to whom the Software is furnished to do so,
 * | subject to the following conditions:
 * |
 * | The above copyright notice and this permission notice shall be
 * | included in all copies or substantial portions of the Software.
 * |
 * | THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * | EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * | OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * | AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * | HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * | WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * | FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * | OTHER DEALINGS IN THE SOFTWARE.
 * |----------------------------------------------------------------------
 */

#include "Jsn.h"

void jsn::setup_uart2(void) {
 Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
}

int jsn::get_distanc() {
	int i,j,result,data[4];
	  i = 0;
#if defined (mode2)
	  Serial2.print(char(0x55));
#endif
	  while (Serial2.available()) {
	    data[i] = Serial2.read();
	    i++;
	    }
	  j = (data[0] + data[1] + data[2])& 0x00FF;    //calculate the amount
	  if (j == data[3]) {           //if the amount is right in the variable result give the distance
	    result = data[1];
	    result = (result<<8);
	    result = result | data[2];
	    return result;
	  } else {
	    return 0;             //if the amount is not right to return zero
	  }
}
