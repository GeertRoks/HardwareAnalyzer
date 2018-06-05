/**************************************************************************
 *
 *  File Name   :   click.cpp
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   *ALTERNATIVE METHOD OF TESTING* Generates a dirac pulse
 *        (or something close to it). It has a variable length of the array
 *        and a variable position of the dirac pulse.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


#include "click.h"

Click::Click(unsigned int testLength, unsigned int clickSample) {
  this->testLength = testLength;
  this->clickSample = clickSample;

  clickSignal = new float[testLength];
  for (size_t i = 0; i < testLength; i++) {
    clickSignal[i] = 0;
  }
  clickSignal[clickSample] = 1;
}//Click()

Click::~Click() {
  delete[] clickSignal;
  clickSignal = nullptr;
}//~Click()

float *Click::getTestsignal() {
  return clickSignal;
}//getTestsignal()
