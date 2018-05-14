/**
  Blueprint for oscillator functions. Calculating and remembering phase and phasesteps.
*/
#ifndef OSCILLATOR_H_
#define OSCILLATOR_H_

#include <iostream>
#include <cmath>

class Oscillator {
public:
  Oscillator();
  Oscillator(float freq);
  ~Oscillator();

  virtual float getSample() = 0;
  void tick();
  void setFreq(float freq, int sampleRate);

protected:
  double phase = 0;
  double phaseStep = 0;

  static constexpr double Pi = 3.14159265358979323846;
  static constexpr double twoPi = 2 * Pi;

private:
  float freq;
  int sampleRate;

};//class

#endif//OSCILLATOR_H_

/*TODO:
    - Remove samplerate input from setFreq and make a void setSampleRate().
    - Osccilator based on polynomials.
*/
