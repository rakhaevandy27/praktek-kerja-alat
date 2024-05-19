#include <Wire.h>
#include <Adafruit_INA219.h>

Adafruit_INA219 ina219;

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    delay(10);
  }

  Serial.println("Hello!");

  // Initialize the INA219 sensor
  if (!ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("Found INA219 chip");

  // Configure INA219
  // ina219.setCalibration_32V_1A();
  // ina219.setCalibration_16V_400mA();
  ina219.setCalibration_32V_2A();
}

void loop() {
  float shuntVoltage = ina219.getShuntVoltage_mV(); // 1000.0; // Convert to volts
  float busVoltage = ina219.getBusVoltage_V();
  float current_mA = ina219.getCurrent_mA();
  float power_mW = ina219.getPower_mW();

  Serial.print("Shunt Voltage: ");
  Serial.print(shuntVoltage);
  Serial.println(" V"); // Changed unit from mV to V

  Serial.print("Bus Voltage: ");
  Serial.print(busVoltage);
  Serial.println(" V");

  Serial.print("Current: ");
  Serial.print(current_mA);
  Serial.println(" mA");

  Serial.print("Power: ");
  Serial.print(power_mW);
  Serial.println(" mW");

  Serial.println();

  delay(1000);
}
