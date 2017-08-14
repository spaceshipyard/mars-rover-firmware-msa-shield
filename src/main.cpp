#include <Arduino.h>
#include <AmperkaMotorShieldMovingPlatform.h>
#include <MarsRoverController.h>




AmperkaMotorShieldMovingPlatform movingPlatform;
MarsRoverController ctrl(&movingPlatform);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.setTimeout(2000);
  // turn on motor
  ctrl.setup();
  //movingPlatform.setup();
  Serial.println("setup completed");
}

void loop() {
  ctrl.onTick();
  delay(100);
}
