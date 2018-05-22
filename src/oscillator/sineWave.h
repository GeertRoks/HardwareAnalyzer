#ifndef SINEWAVE_H_
#define SINEWAVE_H_

#include "oscillator.h"

class Sinewave : public Oscillator {
public:
  Sinewave(float offset, float depth);
  ~Sinewave();

  float getSample() override;

private:
  float offset;
  float depth;
};//class

#endif//SINEWAVE_H_
