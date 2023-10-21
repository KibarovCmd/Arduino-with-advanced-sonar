#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3); int tx = 9, rx = 8; long sure, uzaklik; void setup() { display.begin(); display.setContrast(75);
pinMode(tx, OUTPUT); pinMode(rx, INPUT); } void loop() { display.display(); display.clearDisplay(); while(True) { for(int i = 84; i >= 0; i--) {      
digitalWrite(tx, LOW); delayMicroseconds(5); digitalWrite(tx, HIGH); delayMicroseconds(10); digitalWrite(tx, LOW); sure = pulseIn(rx, HIGH);
uzaklik = sure /29.1/2; uzaklik = map(uzaklik, 0, 500, 0, 48); for(int j = 0; j <= 48; j++) { if(j < uzaklik) { display.setTextSize(1); 
display.setTextColor(BLACK); display.setCursor(i, j); display.println("."); display.display(); } else { display.setTextSize(1); display.setTextColor(WHITE);
display.setCursor(i, j); display.println("."); display.display(); } } } display.clearDisplay(); } }
