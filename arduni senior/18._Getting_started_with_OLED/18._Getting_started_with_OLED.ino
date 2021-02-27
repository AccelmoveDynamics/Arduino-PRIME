#include <Adafruit_GFX.h>      
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64  
#define OLED_RESET     -1 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
display.clearDisplay();
}
void loop() {
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(15,0);
  display.println("Hello World");
  display.display();
}
