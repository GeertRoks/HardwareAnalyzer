
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
