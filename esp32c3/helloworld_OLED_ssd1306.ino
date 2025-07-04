/*
this program uses the Adafruit SSD1306 driver implementation and its graphical libraries 
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display width/height, in pixels
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

// Reset pin (or -1 if sharing reset with microcontroller)
#define OLED_RESET    -1
// I2C address for 128×32 OLEDs
#define SCREEN_ADDRESS 0x3C // 0x3D for 128x64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize I2C and the display
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 init failed"));
    for (;;); // hang if init failed
  }

  // Clear the buffer
  display.clearDisplay();

  // Choose a text size and color
  display.setTextSize(1);             // 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);// Draw white text

  // Position the cursor (x, y)
  display.setCursor(0, 0);

  // Print your message
  display.println(F("Hello, world!"));

  // Actually send the buffer to the display
  display.display();
}

void loop() {
  // nothing to do here
}
