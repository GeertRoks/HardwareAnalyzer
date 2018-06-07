/**************************************************************************
 *
 *  File Name   :   oscillator.h
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   Base class for all oscillators. Calculates and
 *        manages phase and phasesteps for the derived class.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


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
  void setFreq(float freq);
  void setSampleRate(int sampleRate);

protected:
  double phase = 0;
  double phaseStep = 0;

  static constexpr double Pi = 3.14159265358979323846;
  static constexpr double twoPi = 2 * Pi;

private:
  float freq = 440;
  int sampleRate = 48000;
};//class

#endif//OSCILLATOR_H_
