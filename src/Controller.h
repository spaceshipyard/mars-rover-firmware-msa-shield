#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_


#include <Arduino.h>
#include <MovingPlatform.h>



class Controller {
private:
  const MovingPlatform* platform;
public:
  Controller(const MovingPlatform* aPlatform);
  void setup();
  void onTick();

};



#endif /* end of include guard: _CONTROLLER_H_ */
