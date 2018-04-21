
#include <iostream>
#include <thread>
#include <string>

#include "../inc/jack_module/jack_module.h"

#include "test_signal/click.h"


unsigned long chunksize=2048;

bool fire = false;


JackModule jack;
unsigned long samplerate=44100; // default

static void testSignal()
{
float *inbuffer = new float[chunksize];
float *outbuffer = new float[chunksize];

Click click(chunksize, 3);
float *testSignal = click.getTestsignal();


  do {
    jack.readSamples(inbuffer, chunksize);

    if (fire) {
      jack.writeSamples(testSignal, chunksize);
      fire = false;
    } else {
      for(unsigned int x=0; x<chunksize; x++) {
        outbuffer[x] = 0;
      }//for
    }//else

    jack.writeSamples(outbuffer, chunksize);
  } while(true);

} // testSignal()

int main(int argc, char const *argv[]) {

  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();

  samplerate=jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  std::thread audioThread(testSignal);

  while(true)
  {
    /*
      pseudocode:
      if (input == 'fire') {
        fire = true;
      } else {
        fire = false;
      }
    */
    char input;
    std::cin >> input;
    switch (input) {
      case 'f':
        fire = true;
        break;
      default:
        fire = false;
        break;
    }//switch
  }//while
  audioThread.join();

  jack.end();

  return 0;
}//main
