#include <Arduino.h>
#include <AmperkaMotorShieldMovingPlatform.h>
#include <Controller.h>




AmperkaMotorShieldMovingPlatform movingPlatform;
Controller ctrl(movingPlatform);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.setTimeout(2000);
  // turn on motor
  ctrl.setup();
}

void loop() {
  ctrl.onTick();
  delay(100);
}
