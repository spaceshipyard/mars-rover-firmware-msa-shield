#ifndef MOVING_PLATFORM_H
#define MOVING_PLATFORM_H

#include <Arduino.h>

#define FORWARD 1
#define BACKWARD 2
//#define BRAKE 3
#define RELEASE 4
#define uint8_t byte

class MovingPlatform {
public:
  virtual void setup() {};
  virtual void setSpeed(byte value) {};
  virtual void setDirecton(int value) {};
  virtual void rotateToRigth() {};
  virtual void rotateToLeft() {};
  virtual void setRightSpeed(byte speed) {};
  virtual void setLeftSpeed(byte speed) {};
  virtual String getName() { return "undefined"; };
};


#endif /* end of include guard: MOVING_PLATFORM_H */
