
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
