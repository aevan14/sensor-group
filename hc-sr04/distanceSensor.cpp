#include <Arduino.h>
#include "distanceSensor.h"

#define TRIG_PIN 13
#define ECHO_PIN 14

void setupDistance() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float duration_us = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = 0.017 * duration_us;
  return distance_cm;
}

float readDistanceInch() {
  float distance_inch = readDistanceCM();
  return distance_inch / 2.54;
}