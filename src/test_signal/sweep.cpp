/**************************************************************************
 *
 *  File Name   :   sweep.cpp
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


#include "sweep.h"

Sweep::Sweep(int min, int max, int sweepTime) {
// Function: Initialize the sweep with its parameters
//       (lowest value, highest value, sweeptime)
  ramp.setFreq(1/sweepTime); //f = 1 / T
  ramp.setMinMax(min, max);
}//Sweep

Sweep::~Sweep() {
}//~Sweep

float Sweep::process() {
// Function: Generate a sample for the sweep. The Phasor sample value gets
//        used for the frequency of the sinewave (FM).
  sine.setFreq(ramp.getSample());
  return sine.getSample();
}//process()

void Sweep::tick() {
// Function: Calculate the new samples for the two oscillators
  ramp.tick();
  sine.tick();
}//tick()

void setSampleRate(int sampleRate) {
  ramp.setSampleRate(sampleRate);
  sine.setSampleRate(sampleRate);
}//setSampleRate()
