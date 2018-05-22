
#include "phasor.h"

Phasor::Phasor(float offset, float depth) : Oscillator() {
  this->offset = offset;
  this->depth = depth;
}//Phasor()

Phasor::~Phasor() {

}//~Phasor()

float Phasor::getSample() {
  return (phase/Pi) * 0.5 * this->depth + this->offset;
}//getSample()
