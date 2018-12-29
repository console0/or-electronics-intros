#include <dht.h>
#include <LiquidCrystal.h>

/*

Include the dht library from:
http://www.circuitbasics.com/wp-content/uploads/2015/10/DHTLib.zip

*/

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// sensor setup
#define DHTTYPE DHT11   // DHT 11
#define DHT11_PIN 7 
dht DHT;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // wait for the sensor
  delay(1500);
}

void loop() {
  // read the sensor
  int ret = DHT.read11(DHT11_PIN);
  float tempc = DHT.temperature;
  int temp =  DHT.temperature;
  int humi = DHT.humidity;
  int tempf = ((tempc * (9.0/5.0))+32.0);
  // write temp f/c
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempf);
  lcd.print((char)223);
  lcd.print("F/");
  lcd.print(temp);
  lcd.print((char)223);  
  lcd.print("C");
  //write r/h
  lcd.setCursor(0, 1);
  lcd.print("R/H:  ");
  lcd.print(humi);
  lcd.print("%");
  // wait for sensor
  delay(3000);
}
