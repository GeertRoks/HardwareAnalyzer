
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
