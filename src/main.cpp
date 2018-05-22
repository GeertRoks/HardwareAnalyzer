
#include <iostream>

#include "IO/io.h"
#include "oscillator/phasor.h"
#include "oscillator/sweep.h"


int main(int argc, char const *argv[]) {

Sweep sweep(15);

while(1) {
  std::cout << sweep.process() << '\n';
  sweep.tick();
}//while

// May be needed with the bcm2835 library.
  // std::thread analysisThread(&IO::analysis, &io);
  // std::thread testSignalThread(&IO::testSignal, &io);
  //
  // while(true) {
  //   char input;
  //   std::cin >> input;
  //   switch (input) {
  //     case 'f':
  //       io.setFire(true);
  //       break;
  //     default:
  //       io.setFire(false);
  //       break;
  //   }//switch
  // }//while
  //
  // testSignalThread.join();
  // analysisThread.join();


  return 0;
}//main
