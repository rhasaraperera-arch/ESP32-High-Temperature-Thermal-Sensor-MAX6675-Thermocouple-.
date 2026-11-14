#include "max6675.h"

int thermoDO = 19;
int thermoCS = 5;
int thermoCLK = 18;

MAX6675 thermocouple (thermoCLK, thermoCS, thermoDO);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
delay(500);
Serial.println("MAX6675 High-Temperature Sensor Initialized!");
}

void loop() {
  // put your main code here, to run repeatedly:
float celsius = thermocouple.readCelsius();

if(isnan(celsius)) {
  Serial.println("Error:Thermocouple fault or disconnected!");
}
else {
  Serial.print("Current Surface Temperature:");
  Serial.print(celsius);
  Serial.print("C| ");

  float fahrenheit = thermocouple.readFahrenheit();
  Serial.print(fahrenheit);
  Serial.println(" F");

  delay(1000);

}
}
