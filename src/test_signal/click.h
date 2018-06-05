/**************************************************************************
 *
 *  File Name   :   click.h
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
