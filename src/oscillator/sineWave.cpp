
#include "sineWave.h"

SineWave::SineWave() : Oscillator() {
}//SineWave()

SineWave::~SineWave() {

}//~SineWave()

float SineWave::getSample() {
  return sin(phase);
}//getSample()
