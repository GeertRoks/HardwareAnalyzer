#ifndef PHASOR_H_
#define PHASOR_H_

#include "oscillator.h"

class Phasor : public Oscillator {
public:
  Phasor();
  Phasor(float min, float max);
  ~Phasor();

  float getSample() override;
  void setFreq(float freq);
  void setMinMax(float min, float max);

private:
  float offset = 20;
  float depth = 19080;
};//class

#endif//PHASOR_H_

//NOTE:
/*
TODO:
  - Make phasor one shot.
  - input: sweeptime.
*/
