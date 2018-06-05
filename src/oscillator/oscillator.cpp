/**************************************************************************
 *
 *  File Name   :   oscillator.cpp
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


#include "oscillator.h"

Oscillator::Oscillator() {
}//Oscillator()

Oscillator::Oscillator(float freq) {
  setFreq(freq);
}//Oscillator(float)

Oscillator::~Oscillator() {
}//~Oscillator()


void Oscillator::setFreq(float freq) {
/**
  Function: Change the frequency of the oscillator.
  Refrence: http://basicsynth.com/index.php?page=basic
*/
  this->freq = freq;

  phaseStep = (twoPi / this->sampleRate) * this->freq;
}//setFreq()

void Oscillator::tick() {
/**
  Function: Increase the phase index.
*/
  phase = fmod((phase + phaseStep), twoPi);
}//tick()
