/**************************************************************************
 *
 *  File Name   :   sweep.h
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   Generates a sinus that get its frequency sweeped in
 *        a variable time and between variable minimum and maximum values.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


#ifndef SWEEP_H_
#define SWEEP_H_

#include "../oscillator/sineWave.h"
#include "../oscillator/phasor.h"

class Sweep {
public:
  Sweep(int min, int max, int sweepTime);
  virtual ~Sweep();

  float process();
  void tick();

  void setSampleRate(int sampleRate);

private:
 SineWave sine;
 Phasor ramp;
};//class

#endif//SWEEP_H_
