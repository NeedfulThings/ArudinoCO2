#include <LiquidCrystal.h>

#define sensor	A0

LiquidCrystal lcd(12,11,5,4,3,2);

int gasLevel = 0;
String quality = "";

void setup() {
	Serial begin(9600);
	pinMode(sensor,INPUT);

	lcd.begin(16,2);
	lcd.setCursor(0,0);
	lcd.print("          ");
	lcd.setCursor(0,1);
	lcd.print("          ");
	lcd.setCursor(0,0);
	lcd.print(" Luft Sensor ");
	lcd.setCursor(0,1);
	lcd.print("Uff warme 120 s");
	delay(10000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 110 s");
	delay(10000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 100 s");
	delay(20000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 80 s ");
	delay(20000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 60 s ");
	delay(20000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 40 s ");
	delay(20000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 20 s ");
	delay(10000);
	lcd.setCursor(0,1);
	lcd.print("Uff warme 10 s ");
	delay(10000);
	lcd.setCursor(0,0);
	lcd.print("          ");
	lcd.setCursor(0,1);
	lcd.print("          ");
}

void loop() {
	gasLevel = analogRead(sensor);

	if(gasLevel<180) {
		quality = ":+    ";
	}
	else if(gasLevel>180 && gasLevel<225) {
		quality = ":+/-  ";
	}
	else if(gasLevel>225 && gasLevel<300) {
		quality = ":-    ";
	}
	else if(gasLevel>300) {
		quality = ":--   ";
	}

	lcd.setCursor (0,0);
	lcd.print("LuftQuali ist:");
	lcd.setCursor (0,1);
	lcd.print(gasLevel + quality);
	delay(500);
}