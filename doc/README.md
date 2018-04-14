# Hardware Analyser based on Jack

### Concept
A program that plays a click into a hardware device. The output from the the device is recorded by the the program. The program analyses the outputted signal and plots the results in GNUplot.

### Why do this?
I want a device to test my products so I know it really does what I told it to do. Further it is very useful to be able to analyze sound. This can be used in more complex audio equipment like pitch correction, harmonizers and spectrum editors.

### Objectives
  - Keep a logical and useful log of an project, Document everything
  - Raspberry Pi experience
  - Making a standalone product




### Features
  - [ ] Makefile
    - [ ] Basic Makefile
    - [ ] Recursive Makefiles
  - [ ] Test Signal
    - [ ] Generate click
    - [ ] Output click with Jack
  - [ ] Analyse System
    - [ ] Jack input
    - [ ] Impulse Response
  - [ ] GNUplot
    - [ ] Plot incoming Impulse Response
  - [ ] Raspberry Pi
    - [ ] DIY ADC and DAC from [Electrosmash](https://www.electrosmash.com/pedal-pi)
    - [ ] works fully independent from screen and possibly mains power

######  Extra
  - [ ] Convolver
    - [ ] Export Impulse Responses
    - [ ] Convolve input signal with Impulse Response
  - [ ] Callibration circuit (if needed)
    - [ ] If the wires have impact on the measurement
    - [ ] Direct throughput
  - [ ] External input
    - [ ] Potentiometers
    - [ ] Switches

### Schedule
###### week 15
  - Easily expandable Makefile
  - Finish reading Make manual
  - Click signal

###### week 16
  - Jack input and Output working
  - Start researching analysis system

###### week 17
  - Analasis system working for Impulse Responses

###### week 18
  - Vacation

###### week 19
  - Raspberry Pi implementation
  - DIY ADC and DAC

###### week 20
  - GNU plot implementation

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
