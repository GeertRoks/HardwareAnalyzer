# Hardware Analyzer based on Raspberry Pi

Geert Roks, 2018

### Concept
A program that plays a test signal into a hardware device. The output from the device under test is recorded by the program. The program analyses the outputted signal and plots the results in GNUplot. It also exports the impulse response and convolves it with the further input. This way the hardware device that has been tested is now copied.

### Why do this?
I want a device to test my products so I know it really does what I told it to do. Further it is very useful to be able to analyze sound. This can be used in more complex audio equipment like pitch correction, harmonizers and spectrum editors. The convolution part is also a learning moment out of pure curiosity. So it's both useful and educational.

### Objectives
  - Keep a logical and useful log of a project, document everything
  - Raspberry Pi experience
  - Making a standalone product
  - More knowledge of how Makefiles work and can be used
  - Git branches experience
  - Having a fully working system within 8 weeks time


### Features
  - [x] Makefile
    - [x] Basic Makefile
    - [x] Recursive Makefiles
  - [x] Test Signal
    - [x] Generate click (obsolete)
    - [x] Output click with Jack (obsolete)
    - [x] Output signal with GPIO pins (edit: May 7th)
    - [ ] Generate Sweep
  - [ ] Analysis System
    - [x] Jack input (obsolete)
    - [ ] Receive input with GPIO pins (edit: May 7th)
    - [ ] FFt implementation
    - [ ] Put data in a file readable for GNUplot
  - [ ] GNUplot
    - [ ] Plot impulse response of incoming data
  - [ ] Raspberry Pi
    - [ ] DIY ADC and DAC from [Electrosmash](https://www.electrosmash.com/pedal-pi)
    - [ ] works fully independent of a screen (UI with LEDs)

######  Extra
  - [ ] Makefile
    - [ ] Objects in separate directory, but still good dependencies
    - [ ] Build folder with the program and the `obj/` folder
  - [ ] Convolver
    - [ ] Export Impulse Responses
    - [ ] Convolve input signal with Impulse Response
  - [ ] Callibration circuit (if needed)
    - [ ] If the wires have impact on the measurement
    - [ ] Direct throughput
  - [ ] External input/UI
    - [ ] Potentiometers
    - [ ] Switches
    - [ ] Indication LEDs

### Schedule
###### week 15
  - Easily expandable Makefile
  - Finish reading Make manual
  - Click signal

###### week 16
  - Jack input and Output working
  - Start researching analysis system

###### week 17
  - Analysis system for Impulse Responses working

  edit (April 30th):
  - Research analysis techniques

###### week 18
  - Vacation

  edit (April 30th):
  - Raspberry Pi implementation
  - DIY ADC and DAC

###### week 19
  - Raspberry Pi implementation
  - DIY ADC and DAC

  edit (April 30th):
  - Analysis system for Impulse Responses working
  - Output sweep instead of click

###### week 20
  - GNU plot implementation
  - 3D printed enclosure

###### week 21
  - Extra week for possible delay caused by problems

  edit (May 22nd):
  - Sweep output working
  - start Analysis system
###### week 22
  - External Input

  edit (May 22nd):
  - Finish analysis system
  - GNUplot implementation
###### week 23
  - Convolution

  edit (May 22nd):
  - debug and add comments to code
  - Prepare for final presentation
###### week 24
  - Final presentation
