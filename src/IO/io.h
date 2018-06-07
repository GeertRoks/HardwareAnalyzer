/**************************************************************************
 *
 *  File Name   :   io.h
 *  System Name :   HardwareAnalyzer
 *  Version     :   0.1 (not-released)
 *  Author      :   Geert Roks
 *  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
 *
 *  Function    :   *FOR THE FUTURE, IGNORE IT FOR NOW* Manages the input and output of
 *        audio with JACK.
 *
 **************************************************************************
 *
 *  For a description of the program and License see the main.cpp file
 *  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
 *  LICENSE DESCRIBED IN THE main.cpp FILE.
 *
 **************************************************************************/


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
