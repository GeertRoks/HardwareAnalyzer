
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
