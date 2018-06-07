/**************************************************************************
 *
 *  File Name   :   sineWave.h
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   Sinusodal oscillator derived from oscillator.h. Used
 *        for audio purposes.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


#ifndef SINEWAVE_H_
#define SINEWAVE_H_

#include "oscillator.h"

class SineWave : public Oscillator {
public:
  SineWave();
  ~SineWave();

  float getSample() override;
};//class

#endif//SINEWAVE_H_
