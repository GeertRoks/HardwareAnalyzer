#ifndef CLICK_H_
#define CLICK_H_

#include <iostream>

class Click {
public:
  Click (unsigned int testLength, unsigned int clickSample);
  virtual ~Click ();

  float *getTestsignal();

private:
  float *clickSignal;
  unsigned int testLength = 100; //samples
  unsigned int clickSample = 3; //nth sample

};//class

#endif//CLICK_H_
