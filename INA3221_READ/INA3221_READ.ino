#include <Wire.h>
#include <Beastdevices_INA3221.h>
#define PRINT_DEC_POINTS  3         // decimal points to print

// Set I2C address to 0x41 (A0 pin -> VCC)
Beastdevices_INA3221 ina3221(INA3221_ADDR41_VCC);

float voltage[3];
float current[3];

unsigned long previousMillis = 0;
const long interval = 1000;  // Interval in milliseconds


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  while (!Serial) {
      delay(1);
  }

  ina3221.begin();
  ina3221.reset();

  ina3221.setShuntRes(10, 10, 10);//set shunt resistor to 10m0hm
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    read_voltage();
    previousMillis = currentMillis;
  }
  serialprint();
}

void read_voltage(){
  //channel 1
  voltage[0] = ina3221.getVoltage(INA3221_CH1);
  current[0] = ina3221.getCurrent(INA3221_CH1);

  //channel 2
  voltage[1] = ina3221.getVoltage(INA3221_CH2);
  current[1] = ina3221.getCurrent(INA3221_CH2);

  //chanel 3
  voltage[2] = ina3221.getVoltage(INA3221_CH3);
  current[2] = ina3221.getCurrent(INA3221_CH3);
}

void serialprint(){
  Serial.println("===============================");
  Serial.print("Channel 1: ");
  Serial.print(current[0], PRINT_DEC_POINTS);
  Serial.print("A, ");
  Serial.print(voltage[0], PRINT_DEC_POINTS);
  Serial.println("V");

  Serial.print("Channel 2: ");
  Serial.print(current[1], PRINT_DEC_POINTS);
  Serial.print("A, ");
  Serial.print(voltage[1], PRINT_DEC_POINTS);
  Serial.println("V");

  Serial.print("Channel 3: ");
  Serial.print(current[2], PRINT_DEC_POINTS);
  Serial.print("A, ");
  Serial.print(voltage[2], PRINT_DEC_POINTS);
  Serial.println("V");
  Serial.println("===============================");

  delay(1000);
}
