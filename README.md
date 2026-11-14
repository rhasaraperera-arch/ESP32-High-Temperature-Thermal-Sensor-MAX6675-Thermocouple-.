# ESP32-High-Temperature-Thermal-Sensor-MAX6675-Thermocouple-.
An industrial-grade temperature monitoring node built with an *ESP32 (CP2102)* and a *MAX6675 K-Type Thermocouple Module, capable of measuring high temperatures from 0°C to 800°C via SPI communication.

This project was developed as part of an industrial automation practice series tailored for garment manufacturing environments—such as monitoring heat presses, fusing machines, and steam ironing stations where standard environmental sensors cannot operate.

---

## 🛠️ Hardware Components

* *Microcontroller:* ESP32 Development Board (CP2102, 30-Pin)
* *Sensor Module:* MAX6675 Thermocouple Temperature Sensor (0–800°C) with K-Type Probe
* *Wiring:* Female-to-Female Jumper Wires

---

## 🔌 Circuit Wiring & Pinout

The MAX6675 interfaces with the ESP32 using the *SPI (Serial Peripheral Interface)* protocol:

| MAX6675 Pin | ESP32 Pin | Function |
| :--- | :--- | :--- |
| *GND* | GND | Ground |
| *VCC* | 3V3 | 3.3V Power Supply |
| *SCK* | GPIO 18 | SPI Serial Clock |
| *CS* | GPIO 5 | SPI Chip Select |
| *SO* | GPIO 19 | SPI Data Out (MISO) |

---

## 💻 Software & Dependencies

1. *IDE:* Arduino IDE (with ESP32 Board Manager installed)
2. *Library:* MAX6675 library by Adafruit (Install via *Sketch > Include Library > Manage Libraries*)

---

## 📜 Source Code (main.ino)

```cpp
#include "max6675.h"

// Define SPI pin connections
int thermoDO = 19;  // SO (Data Out)
int thermoCS = 5;   // CS (Chip Select)
int thermoCLK = 18; // SCK (Clock)

// Initialize the thermocouple object
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(115200);
  // Allow the MAX6675 chip to stabilize
  delay(500);
  Serial.println("MAX6675 High-Temperature Sensor Initialized!");
}

void loop() {
  // Read temperature in Celsius
  float celsius = thermocouple.readCelsius();
  
  // Fault detection: Check if the thermocouple is disconnected or failing
  if (isnan(celsius)) {
    Serial.println("Error: Thermocouple fault or disconnected!");
  } else {
    Serial.print("Current Surface Temperature: ");
    Serial.print(celsius);
    Serial.print(" °C  |  ");
    
    float fahrenheit = thermocouple.readFahrenheit();
    Serial.print(fahrenheit);
    Serial.println(" °F");
  }

  // Sample every 1 second
  delay(1000);
}
