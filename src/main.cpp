
#include <iostream>
#include "test_signal/click.h"


int main(int argc, char const *argv[]) {
  Click click(16, 3);
  float *testSignal = click.getTestsignal();
  for(int i = 0; i < 16; i++){
    std::cout << testSignal[i] << std::endl;
  }//for

  return 0;
}//main
