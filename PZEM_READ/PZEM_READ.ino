#include <PZEM004Tv30.h>
#include <SoftwareSerial.h>

/* Use software serial for the PZEM
 * Pin 12 Rx (Connects to the Tx pin on the PZEM)
 * Pin 13 Tx (Connects to the Rx pin on the PZEM)
*/
#if !defined(PZEM_RX_PIN) && !defined(PZEM_TX_PIN)
  #define PZEM_RX_PIN 12
  #define PZEM_TX_PIN 13
#endif

SoftwareSerial pzemSWSerial(PZEM_RX_PIN, PZEM_TX_PIN);
PZEM004Tv30 pzem(pzemSWSerial);

//variable
float voltage_ac;
float current_ac;
float power_ac;
float energy_ac;
float frequency_ac;
float pf;

unsigned long previousMillis = 0;
const long interval = 1000;  // Interval in milliseconds

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Save the last time we blinked the LED
    readpzem();
    previousMillis = currentMillis;
  }
  print_data();
}

void readpzem(){
  voltage_ac=pzem.voltage();
  current_ac=pzem.current();
  power_ac=pzem.power();
  energy_ac=pzem.energy();
  frequency_ac=pzem.frequency();
  pf=pzem.pf();
}

void print_data(){
  if(isnan(voltage_ac)){
        Serial.println("Error reading voltage");
    } else if (isnan(current_ac)) {
        Serial.println("Error reading current");
    } else if (isnan(power_ac)) {
        Serial.println("Error reading power");
    } else if (isnan(energy_ac)) {
        Serial.println("Error reading energy");
    } else if (isnan(frequency_ac)) {
        Serial.println("Error reading frequency");
    } else if (isnan(pf)) {
        Serial.println("Error reading power factor");
    }else{
        Serial.print("Voltage: ");      Serial.print(voltage_ac);      Serial.println("V");
        Serial.print("Current: ");      Serial.print(current_ac);      Serial.println("A");
        Serial.print("Power: ");        Serial.print(power_ac);        Serial.println("W");
        Serial.print("Energy: ");       Serial.print(energy_ac,3);     Serial.println("kWh");
        Serial.print("Frequency: ");    Serial.print(frequency_ac, 1); Serial.println("Hz");
        Serial.print("PF: ");           Serial.println(pf);
    }
    delay(1000);
}
