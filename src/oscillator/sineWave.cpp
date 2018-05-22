
#include "sineWave.h"

SineWave::SineWave(float freq) : Oscillator() {
  this->freq = freq;
}//SineWave()

SineWave::~SineWave() {

}//~SineWave()

float SineWave::getSample() {
  return sin(phase);
}//getSample()
