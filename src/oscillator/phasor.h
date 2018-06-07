/**************************************************************************
 *
 *  File Name   :   phasor.h
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   Logarithmic ramp oscillator derived from oscillator.h.
 *         USED FOR CONTROL VALUES. DO NOT USE AS AUDIO OSCILLATOR!
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


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
  double growth = pow(20000/20, 1/twoPi);
};//class

#endif//PHASOR_H_
