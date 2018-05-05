#ifndef IO_H
#define IO_H

#include <iostream>
#include <thread>
#include <string>

#include "../test_signal/click.h"

class IO {
public:
  IO();
  virtual ~IO();

  void testSignal();
  void analysis();
  void setFire(bool fire);

private:
  bool fire = false;
  unsigned long chunksize = 2048;

};//class

#endif//IO_H
