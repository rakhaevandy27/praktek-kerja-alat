#include <Keypad.h>

const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte colPins[COLS] = {5, 4, 3, 2}; // Connect keypad COL0, COL1 and COL2 to these Arduino pins.
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

unsigned long previousMillis = 0;
const long interval = 100; // Interval in milliseconds

void setup() {
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time to read the keypad
  if (currentMillis - previousMillis >= interval) {
    char key = keypad.getKey();
    if (key != NO_KEY) {
      switch(key) {
        case '1':
          Serial.println("Option 1 selected");
          // Your code for option 1
          break;
        case '2':
          Serial.println("Option 2 selected");
          // Your code for option 2
          break;
        case '3':
          Serial.println("Option 3 selected");
          // Your code for option 3
          break;
        case 'A':
          Serial.println("Option A selected");
          // Your code for option A
          break;
        case 'B':
          Serial.println("Option B selected");
          // Your code for option B
          break;
        case 'C':
          Serial.println("Option C selected");
          // Your code for option C
          break;
        case 'D':
          Serial.println("Option D selected");
          // Your code for option D
          break;
        default:
          Serial.println("Invalid option");
          break;
      }
    }
    previousMillis = currentMillis; // Update the previousMillis
  }
  
  // Your other non-blocking code can go here
}
