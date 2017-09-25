#include <AmperkaMotorShieldMovingPlatform.h>
#include <Arduino.h>


// Моторы подключаются к клеммам M1+, M1-, M2+, M2-
// Если полюса моторов окажутся перепутаны при подключении,
// можно изменить соответствующие константы CON_MOTOR с 0 на 1
#define CON_MOTOR1     0
#define CON_MOTOR2     0

// Motor shield использует четыре контакта 4, 5, 6, 7 для управления моторами
// 4 и 7 — для направления, 5 и 6 — для скорости
#define SPEED_1      5
#define DIR_1        4

#define SPEED_2      6
#define DIR_2        7

class MotorInfo {
public:
  int speedPin;
  int dirPin;
  MotorInfo(int speedPin, int dirPin): speedPin(speedPin), dirPin(dirPin) {
  }
};

MotorInfo leftMotorInfo(SPEED_1, DIR_1);
MotorInfo rightMotorInfo(SPEED_2, DIR_2);

void setMotorSpeed(const MotorInfo& motorInfo, byte speed) {
  analogWrite(motorInfo.speedPin, speed);
}

void setMotorDir(const MotorInfo& motorInfo, int direction) {
  switch (direction) {
    case FORWARD: digitalWrite(motorInfo.dirPin, true); break;
    case BACKWARD: digitalWrite(motorInfo.dirPin, false); break;
    case RELEASE:
    default:
      setMotorSpeed(motorInfo, 0);
  }
}

void setLeftMotorDir(int direction) {
  setMotorDir(leftMotorInfo, direction);
}

void setLeftMotorSpeed(int speed) {
  setMotorSpeed(leftMotorInfo, speed);
}

void setRightMotorDir(int direction) {
  setMotorDir(rightMotorInfo, direction);
}

void setRightMotorSpeed(byte speed) {
  setMotorSpeed(rightMotorInfo, speed);
}


AmperkaMotorShieldMovingPlatform::AmperkaMotorShieldMovingPlatform() {};
void AmperkaMotorShieldMovingPlatform::setup() {
  for(int i = 4; i <= 7; i++)
    pinMode(i, OUTPUT);

  setLeftMotorSpeed(255);
  setRightMotorSpeed(255);
};

void AmperkaMotorShieldMovingPlatform::setDirecton(int dir) {
      setLeftMotorDir(dir);
      setRightMotorDir(dir);
};

void AmperkaMotorShieldMovingPlatform::setSpeed(byte speed) {
  setLeftMotorSpeed(speed);
  setRightMotorSpeed(speed);
};

void AmperkaMotorShieldMovingPlatform::rotateToLeft() {
  setLeftMotorDir(FORWARD);
  setRightMotorDir(BACKWARD);
};

void AmperkaMotorShieldMovingPlatform::rotateToRigth() {
  setLeftMotorDir(BACKWARD);
  setRightMotorDir(FORWARD);
};

void AmperkaMotorShieldMovingPlatform::setLeftSpeed(byte speed) {
  setLeftMotorSpeed(speed);
};
void AmperkaMotorShieldMovingPlatform::setRightSpeed(byte speed) {
  setLeftMotorSpeed(speed);
};