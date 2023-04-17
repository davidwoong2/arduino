#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SimpleDHT.h>

LiquidCrystal_I2C lcd(0x3F,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int pinDHT11 = 2;

SimpleDHT11 dht11(pinDHT11);
int cds = A1; // Analog input pin that the potentiometer is attached to
int cdsValue = 0; // value read from the pot
void setup() {
Serial.begin(9600);
lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}
void loop() {
cdsValue  = analogRead(cds); // read the analog in value:
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");
  
  lcd.setCursor(3,0);
  lcd.print("cds : ");
  lcd.print(cdsValue);
}
