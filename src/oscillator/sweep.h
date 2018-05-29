#ifndef SWEEP_H_
#define SWEEP_H_

#include "sineWave.h"
#include "phasor.h"

class Sweep {
public:
  Sweep(int sweepTime);
  virtual ~Sweep();

  float process();
  void tick();

private:
 int sweepTime = 15; //in seconds
 SineWave sine;
 Phasor ramp;

};//class

#endif//SWEEP_H_
