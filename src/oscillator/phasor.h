

#ifndef PHASOR_H_
#define PHASOR_H_

#include "oscillator.h"

class Phasor : public Oscillator {
public:
  Phasor(float offset, float depth);
  ~Phasor();

  float getSample() override;

private:
  float offset;
  float depth;
};//class

#endif//PHASOR_H_
