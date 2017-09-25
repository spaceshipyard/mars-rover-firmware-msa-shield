#include <Arduino.h>
#include <AmperkaMotorShieldMovingPlatform.h>
#include <ArduinoJsonRpc.h>

int strToDirection(const String str) {
  if (str == "FORWARD") {
    return (FORWARD);
  } else if (str == "BACKWARD") {
    return (BACKWARD);
  } else if (str == "RELEASE") {
    return (RELEASE);
  }

  return RELEASE;
}

AmperkaMotorShieldMovingPlatform movingPlatform;

CommandResult setDirection(const JsonObject& inParams, JsonObject& outParams) {
  movingPlatform.setDirecton(strToDirection(inParams["value"].asString()));
  return processed;
}

CommandResult rotateLeft(const JsonObject& inParams, JsonObject& outParams) {
  movingPlatform.rotateToLeft();
  return processed;
}

CommandResult rotateRight(const JsonObject& inParams, JsonObject& outParams) {
  movingPlatform.rotateToRigth();
  return processed;
}

CommandResult speedLeft(const JsonObject& inParams, JsonObject& outParams) {
  movingPlatform.setLeftSpeed(inParams["value"]);
  return processed;
}

CommandResult speedRight(const JsonObject& inParams, JsonObject& outParams) {
  movingPlatform.setRightSpeed(inParams["value"]);
  return processed;
}

CommandResult speed(const JsonObject& inParams, JsonObject& outParams) {
  movingPlatform.setSpeed(inParams["value"]);
  return processed;
}

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  movingPlatform.setup();
  attachCommandProcessor("direction", &setDirection);
  attachCommandProcessor("rotate-left", &rotateLeft);
  attachCommandProcessor("rotate-right", &rotateRight);
  attachCommandProcessor("speed-left", &speedLeft);
  attachCommandProcessor("speed-right", &speedRight);
  attachCommandProcessor("speed", &speed);
}

void loop() {
  tryToReadNextCmd(Serial);
  delay(100);
}
