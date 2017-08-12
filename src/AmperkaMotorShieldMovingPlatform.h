#ifndef _AMPERKA_MOTOR_SHIELD_MOVING_PLATFORM_H
#define _AMPERKA_MOTOR_SHIELD_MOVING_PLATFORM_H

#include <MovingPlatform.h>
#include <Arduino.h>


class AmperkaMotorShieldMovingPlatform : public MovingPlatform {

private:


public:
  AmperkaMotorShieldMovingPlatform();

  void setup() override;

  void setDirecton(int dir) override;

  void setSpeed(byte speed) override;

  void rotateToLeft() override;

  void rotateToRigth() override;

  void setLeftSpeed(byte speed) override;

  void setRightSpeed(byte speed) override;

};


#endif /* end of include guard: _AMPERKA_MOTOR_SHIELD_MOVING_PLATFORM_H
 */
