
#include <iostream>

#include "IO/io.h"
#include "oscillator/sineWave.h"
#include "oscillator/sweep.h"
#include "../inc/jack_module/jack_module.h"

unsigned long chunksize=2048;
JackModule jack;
unsigned long samplerate=44100; // default

int main(int argc, char const *argv[]) {

  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();

  samplerate=jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  Sweep sweep(15);

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
