
#include "phasor.h"

Phasor::Phasor() {
}//Phasor()

Phasor::Phasor(float min, float max) : Oscillator(0.0625) {
  this->offset = min;
  this->depth = max - min;
}//Phasor()

Phasor::~Phasor() {

}//~Phasor()

float Phasor::getSample() {
  return (phase/Pi) * 0.5 * this->depth + this->offset;
}//getSample()

void Phasor::setMinMax(float min, float max) {
  this->offset = min;
  this->depth = max - min;
}//getMinMax()
