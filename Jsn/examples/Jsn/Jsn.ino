#include <Jsn.h>
// defines variables
int distance;
jsn myjsn;
void setup() {
Serial.begin(115200); // Starts the serial communication
myjsn.setup_uart2();
}

void loop() {
distance = myjsn.get_distanc();

// Prints the distance on the Serial
Serial.print("Distance: ");
Serial.println(distance);
delay(100);
}
