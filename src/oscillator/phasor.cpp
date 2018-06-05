/**************************************************************************
 *
 *  File Name   :   phasor.cpp
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   Logarithmic ramp oscillator derived from oscillator.h.
 *         Used for control values instead of audio values.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


#include "phasor.h"

Phasor::Phasor() : Oscillator(0.0625) {
}//Phasor()

Phasor::Phasor(float min, float max) : Oscillator(0.0625) {
  this->offset = min;
  this->growth = pow(max/this->offset, 1/twoPi);
}//Phasor()

Phasor::~Phasor() {

}//~Phasor()

float Phasor::getSample() {
  //return (phase/Pi) * 0.5 * this->depth + this->offset;
  return this->offset * pow(this->growth, phase);
}//getSample()

void Phasor::setMinMax(float min, float max) {
  this->offset = min;
  this->growth = pow(max/this->offset, 1/twoPi);
}//getMinMax()
