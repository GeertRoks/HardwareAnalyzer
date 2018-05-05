
#include <iostream>

#include "../inc/jack_module/jack_module.h"

#include "IO/io.h"


int main(int argc, char const *argv[]) {

  unsigned long samplerate = 44100; // default

  JackModule jack;
  IO io;

  jack.init(argv[0]); // use program name as JACK client name
  jack.autoConnect();

  samplerate = jack.getSamplerate();
  std::cerr << "Samplerate: " << samplerate << std::endl;

  std::thread analysisThread(&IO::analysis, &io);
  std::thread testSignalThread(&IO::testSignal, &io);

  while(true) {
    char input;
    std::cin >> input;
    switch (input) {
      case 'f':
        io.setFire(true);
        break;
      default:
        io.setFire(false);
        break;
    }//switch
  }//while

  testSignalThread.join();
  analysisThread.join();

  jack.end();

  return 0;
}//main
