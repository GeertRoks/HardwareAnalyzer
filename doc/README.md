# Hardware Analyser based on Jack

Geert Roks, 2018

### Concept
A program that plays a click into a hardware device. The output from the the device is recorded by the the program. The program analyses the outputted signal and plots the results in GNUplot.

### Why do this?
I want a device to test my products so I know it really does what I told it to do. Further it is very useful to be able to analyze sound. This can be used in more complex audio equipment like pitch correction, harmonizers and spectrum editors.

### Objectives
  - Keep a logical and useful log of a project, document everything
  - Raspberry Pi experience
  - Making a standalone product
  - More knowledge of how Makefiles work and can be used


### Features
  - [x] Makefile
    - [x] Basic Makefile
    - [x] Recursive Makefiles
  - [x] Test Signal
    - [x] Generate click
    - [x] Output click with Jack
    - [ ] Generate Sweep
  - [ ] Analysis System
    - [x] Jack input
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

  edit (april 30th):
  - Research analysis techniques.

###### week 18
  - Vacation

  edit (april 30th):
  - Raspberry Pi implementation
  - DIY ADC and DAC

###### week 19
  - Raspberry Pi implementation
  - DIY ADC and DAC

  edit (april 30th):
  - Analysis system for Impulse Responses working
  - Output Sweep instead of click

###### week 20
  - GNU plot implementation
  - 3D printed enclosure

###### week 21
  - Extra week for possible delay caused by problems
  - (?) possible extra's like External input

###### week 22
  - Convolution start
  - Research + export IR

###### week 23
  - Second week for Convolution
  - Finish convolution

###### week 24
  - Final presentation
