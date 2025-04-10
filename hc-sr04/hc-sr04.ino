#include "distanceSensor.h"

void setup() {
  Serial.begin(115200);
  setupDistance();
}

void loop() {
  float cm = readDistanceCM();
  float inch = readDistanceInch();

  Serial.print("Distance: ");
  Serial.print(cm);
  Serial.print(" cm / ");
  Serial.print(inch);
  Serial.println(" inch");
 
  delay(500);
}
