#include <Keyboard.h>

// see https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/#functions


void setup() {
  Keyboard.begin();
  delay(2000); 

}
// Press the BOOT button to print the message 
void loop() {
  if (BOOTSEL) {  // anti spam guard
    Keyboard.print("Hello World");
    delay(100);

  }
}
