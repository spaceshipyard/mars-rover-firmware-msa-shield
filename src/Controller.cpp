#include <Arduino.h>
#include <MovingPlatform.h>
#include <Controller.h>


int strToDirection(String str) {
  if (str == "FORWARD") {
    return (FORWARD);
  } else if (str == "BACKWARD") {
    return (BACKWARD);
  } else if (str == "RELEASE") {
    return (RELEASE);
  }

  return RELEASE;
}

Controller::Controller(const MovingPlatform* aPlatform): platform(aPlatform) {
}

void Controller::setup() {
    Serial.println("controller setup started");
    Serial.println(this->platform->getName());
    this->platform->setup();
    Serial.println("controller setup completed");
}

void Controller::onTick() {
    while (Serial.available() > 0) {
      String cmd = Serial.readStringUntil(':');
      Serial.println(cmd);
      if (cmd == "direction") {
        String dirStr = Serial.readStringUntil(';');
        int dir = strToDirection(dirStr);
        platform->setDirecton(dir);

      } else if (cmd == "speed")  {
        String speedStr = Serial.readStringUntil(';');
        platform->setSpeed(speedStr.toInt());

      } else if (cmd == "dir-left") {
        String dirStr = Serial.readStringUntil(';');

        platform->rotateToLeft();

      } else if (cmd == "dir-right") {
        String dirStr = Serial.readStringUntil(';');
        platform->rotateToRigth();

      } else if (cmd == "speed-left") {
        String speedStr = Serial.readStringUntil(';');
        platform->setLeftSpeed(speedStr.toInt());

      } else if (cmd == "speed-right") {

        String speedStr = Serial.readStringUntil(';');

        platform->setRightSpeed(speedStr.toInt());
      }
    }
  }
