
#include "sweep.h"

Sweep::Sweep(int sweepTime) {
  this->sweepTime = sweepTime;

}//Sweep

Sweep::~Sweep() {

}//~Sweep

float Sweep::process() {
  sine.setFreq(ramp.getSample());
  return sine.getSample();
}//process()

void Sweep::tick() {
  ramp.tick();
  sine.tick();
}//tick()
