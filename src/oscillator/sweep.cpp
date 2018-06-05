/**************************************************************************
 *
 *  File Name   :   sweep.cpp
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   Generates a sinus that get its frequency sweeped in
 *        a variable time and between variable minimum and maximum values.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


#include "sweep.h"

Sweep::Sweep(int sweepTime) {
  this->sweepTime = sweepTime;
  ramp.setMinMax(20, 20000);
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
