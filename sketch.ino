#include <OneWire.h> 
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#define ONE_WIRE 13
#define HEATER_PIN 4

OneWire oneWire(ONE_WIRE);
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 20, 4);

String H_state = "IDLE          ";

void setup() {

  Serial.begin(115200);
  sensors.begin();

   pinMode(HEATER_PIN, OUTPUT); //LED

   lcd.init();
   lcd.backlight();

}

void loop() {
  // // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  //Serial.println(temp);
  //delay(1000);
   HeaterStatus(temp);
   controlHeater(H_state);
   lcd_display(temp);
   serial_log(temp,H_state);
}
void HeaterStatus(float temp){
   if (temp > 70.0) {
    H_state = "OVERHEAT      ";
  } else if (temp >= 49.0 && temp <= 51.0) {
    H_state = "TARGET_REACHED";
  } else if (temp >= 48.0 && temp < 52.0) {
    H_state = "STABILIZING   ";
  } else if (temp < 48.0) {
    H_state = "HEATING       ";
  } else {
    H_state = "IDLE          ";
  }
}
void controlHeater(String H_state) {
  if (H_state == "HEATING       " || H_state == "STABILIZING   ") {
    digitalWrite(HEATER_PIN, HIGH);

    lcd.setCursor(5,3);
    lcd.print("Heater ON ");
  } else {
    digitalWrite(HEATER_PIN, LOW);

    lcd.setCursor(5,3);
    lcd.print("Heater OFF");
  }
}

void lcd_display(float temp) {
 // lcd.clear();
 

  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C ");
  
  lcd.setCursor(0,1);
  lcd.print("State:");
  lcd.print(H_state);
}

void serial_log(float temp, String H_state)
{
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("°C | Heater State: ");
  Serial.println(H_state);
}