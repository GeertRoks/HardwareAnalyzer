/**************************************************************************
 *
 *  File Name   :   phasor.cpp
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


#include "phasor.h"

Phasor::Phasor() : Oscillator(0.0625) {
// Function: Initialize Phasor oscillator with a default sweep time of 15
//        seconds (1/15 = 0.0625). Use the default offset and growth values.
}//Phasor()

Phasor::Phasor(float min, float max) : Oscillator(0.0625) {
// Function: Initialize Phasor oscillator with a default sweep time of 15
//        seconds (1/15 = 0.0625). Sweep between the min and max value.
  this->offset = min;
  this->growth = pow(max/min, 1/twoPi);
}//Phasor()

Phasor::~Phasor() {

}//~Phasor()

float Phasor::getSample() {
// Function: Generate the phasor samples. Based of the logarithmic formula:
//        F(x) = a * g^x where a is the begin value and g the growth factor.
  return this->offset * pow(this->growth, phase);
}//getSample()

void Phasor::setMinMax(float min, float max) {
// Function: Set different minimum and maximum values for the oscillator.
  this->offset = min;
  this->growth = pow(max/min, 1/twoPi);
}//getMinMax()
