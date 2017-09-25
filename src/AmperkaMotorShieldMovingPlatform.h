#ifndef _AMPERKA_MOTOR_SHIELD_MOVING_PLATFORM_H
#define _AMPERKA_MOTOR_SHIELD_MOVING_PLATFORM_H

#include <Arduino.h>

#define FORWARD 1
#define BACKWARD 2
//#define BRAKE 3
#define RELEASE 4

#define uint8_t byte


class AmperkaMotorShieldMovingPlatform {

private:


public:
  AmperkaMotorShieldMovingPlatform();

  void setup();

  void setDirecton(int dir);

  void setSpeed(byte speed);

  void rotateToLeft();

  void rotateToRigth();

  void setLeftSpeed(byte speed);

  void setRightSpeed(byte speed);
};


#endif /* end of include guard: _AMPERKA_MOTOR_SHIELD_MOVING_PLATFORM_H
 */
