# Heater-control-system
Basic heater control system using ESP32 and DS18B20.
This project simulates a heater control system using ESP32 and a temperature sensor (DS18B20). It monitors temperature and adjusts heater state with visual feedback.

## 📦 Features

- Real-time temperature monitoring using DS18B20
- Heater control logic with defined states:
  - IDLE, HEATING, STABILIZING, TARGET REACHED, OVERHEAT
- LCD (20x4) display for live feedback
- Serial logging of temperature and heater state
- Built using Arduino framework (ESP32)
-  Simulatable on [Wokwi](https://wokwi.com)

 ## 🔌 Hardware Components

- ESP32
- DS18B20 temperature sensor
- I2C LCD (20x4)
- 1x LED (simulated heater)
- Resistors and breadboard (if hardware build)

 ## 🛠️ Setup Instructions

1. Clone or Download this repo
2. Open in Arduino IDE / Wokwi
3. Install libraries:
   - OneWire
   - DallasTemperature
   - LiquidCrystal_I2C

   ## 🚦 Heater Control Logic

| Temperature Range (°C) | State            | Heater     |
|------------------------|------------------|------------|
| < 48.0                 | HEATING          | ON         |
| 48.0 – 49.9            | STABILIZING      | ON         |
| 49.9 – 51.0            | TARGET_REACHED   | OFF        |
| > 70.0                 | OVERHEAT         | OFF        |
| Else                   | IDLE             | OFF        |



## 🧪 Simulation (Wokwi)

You can simulate this project online via Wokwi. Link:  
👉 [Wokwi Simulation](https://wokwi.com/projects/436898967308438529)
