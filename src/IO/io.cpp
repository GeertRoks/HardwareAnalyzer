/**************************************************************************
 *
 *  File Name   :   io.cpp
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   *FOR THE FUTURE* Manages the input and output of
 *        audio with JACK.
 *
 **************************************************************************
 *
 *  For a description of the program and the License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


#include "io.h"

IO::IO() {
}//IO()

IO::~IO() {

}//~IO


void IO::testSignal() {
float *outbuffer = new float[chunksize];

Click click(chunksize, 3);
float *testSignal = click.getTestsignal();

  do {
    if (fire) {
      //jack.writeSamples(testSignal, chunksize);
      fire = false;
    } else {
      for(unsigned int x = 0; x < chunksize; x++) {
        outbuffer[x] = 0;
      }//for
    }//else

    //jack.writeSamples(outbuffer, chunksize);
  } while(true);
} // testSignal()


void IO::analysis() {
float *inbuffer = new float[chunksize];

  do {

    //jack.readSamples(inbuffer, chunksize);
  } while(true);
} // analysis()

void IO::setFire(bool fire) {
  this->fire = fire;
}//fire()
