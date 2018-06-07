/**************************************************************************
 *
 *  File Name   :   main.cpp
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   The main file that combines the program. It manages
 *        the instances of classes and contains the audio wirte loop.
 *
 **************************************************************************
 *
 *  Description :   A program that plays a test signal into a hardware
 *        device. The output from the device under test is recorded by
 *        the program. The program analyses the outputted signal and plots
 *        the results in GNUplot. It also exports the impulse response and
 *        convolves it with the further input. This way the hardware device
 *        that has been tested is now copied. This program will run on a
 *        Raspberry Pi. See doc/README.md for more info.
 *
 **************************************************************************
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 **************************************************************************/


#include <iostream>

#include "oscillator/sweep.h"
#include "../inc/jack_module/jack_module.h"


int main(int argc, char const *argv[]) {

  unsigned long chunksize = 2048;
  unsigned long sampleRate = 44100;

  //Initialize the JackModule
  JackModule jack;
  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();
  sampleRate = jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  //Initialize a sweep oscillator that sweeps from 20 to 20000 Hz in 15 seconds
  Sweep sweep(20, 20000, 15);
  sweep.setSampleRate(sampleRate);

  //write the samples to JACK
  float *outbuffer = new float[chunksize];
  while(true) {
    for(unsigned int x = 0; x < chunksize; x++) {
      outbuffer[x] = sweep.process();
      sweep.tick();
    }//for
    jack.writeSamples(outbuffer, chunksize);
  }//while

  jack.end();

  return 0;
}//main


/* TODO:
  - Make phasor one shot.
  - Make sinewave without the sin() function (polynomial or wavetable)
*/
