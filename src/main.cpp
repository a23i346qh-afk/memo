#include <Arduino.h>
#include "new.h"
// put function declarations here:
int myFunction(int, int);

void setup() {
  // put your setup code here, to run once:
  pinMode(16,OUTPUT);
}

void loop() {
    digitalWrite(16,HIGH);
    delay(1000);
    digitalWrite(16,LOW);
    delay(1000);
    LED();

}