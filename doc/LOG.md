# LOG

##### This is a logbook of the Hardware Analyzer project I'm doing for my Creative Systems Design class at the HKU.

## Current Bugs

- First fire doesn't give a click.

## Fixed Bugs

## Subjects

#### Make

###### Pattern rules
https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html


#### Installing programs on Linux

###### JACK
- Download [Jack 2](http://jackaudio.org/downloads/). My version is `1.9.12`
- Unpack tar.gz with `tar -xvzf jack2-<verion>.tar.gz` in the terminal.
- Go to the unpacked directory. `cd jack2-<version>`
- then install with the following code from the [Wiki](http://jackaudio.org/faq/build_info.html):
~~~
./waf configure
./waf
sudo ./waf install
~~~

###### Atom
I got this from the [Atom Flight-manual](https://flight-manual.atom.io/getting-started/sections/installing-atom/).
~~~
curl -L https://packagecloud.io/AtomEditor/atom/gpgkey | sudo apt-key add -
sudo sh -c 'echo "deb [arch=amd64] https://packagecloud.io/AtomEditor/atom/any/ any main" > /etc/apt/sources.list.d/atom.list'
sudo apt-get update
sudo apt-get install atom
~~~

###### Git
To install git. Just use this command for Debian-based distros. For other OS see [this page](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git).
~~~
sudo apt install git-all
~~~

If you have problems with git-daemon-run. Use this I found on a [forum](https://askubuntu.com/questions/765565/how-to-fix-processing-with-runit-and-git-daemon-run).
~~~
sudo apt-get purge runit
sudo apt-get purge git-all
sudo apt-get purge git
sudo apt-get autoremove
sudo apt update
sudo apt install git
~~~

###### Libre Office
Download the Libre Office package from their [site](https://nl.libreoffice.org/download/libreoffice-fris/)
Unpack the tar with `tar -xvzf LibreOffice_<version>.tar.gz`
Read the Readme to see what to do for your distro.
For Debian-based operating system like Elementary OS go to the DEBS folder in the unpacked tar folder and type:
~~~
sudo dpkg -i *.deb
~~~

###### Spotify
Having some good tunes during programming is essential.
I got this from the [Spotify website](https://www.spotify.com/nl/download/linux/):

1. Add the Spotify repository signing keys to be able to verify downloaded packages
2. Add the Spotify repository
3. Update list of available packages
4. Install Spotify

~~~
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 0DF731E45CE24F27EEEB1450EFDC8610341D9410
echo deb http://repository.spotify.com stable non-free | sudo tee /etc/apt/sources.list.d/spotify.list
sudo apt-get update
sudo apt-get install spotify-client
~~~

#### Raspberry Pi

###### Connecting via SSH (Linux)
I learned that this was a possibility in my Maker skills class from Mark IJzerman. Jochem van Iterson showed me one day when I were trying to figure it out. So I remembered some things about it, but [this video](https://www.youtube.com/watch?v=JJyFLNC2cFM) completely refreshed my memory.
This method uses a connection between your computer and the Raspberry Pi via an Ethernet cable. When you followed the instructions in the video you can control the Pi from the command line of your (Linux) machine.
First installation (see [video](https://www.youtube.com/watch?v=JJyFLNC2cFM)):
~~~
1. Configure VPN Network
2. Connect the Pi to your computer via a Ethernet cable
3. Follow next steps
~~~

Connect to Pi
~~~
cat /var/lib/misc/dnsmasq.leases
ssh pi@<ip_adres>
~~~
For me its almost everytime: `10.42.0.31`
Default password of the Pi is: `raspberry`

It's recommended to [change the password](https://www.raspberrypi.org/forums/viewtopic.php?t=193620).
~~~
sudo raspi-config
choose option: Change User Password
~~~
To shutdown the Pi
~~~
sudo shutdown -h now
~~~

###### BCM2835 installation
I learned this from [this video](https://www.youtube.com/watch?v=KwSq-WxNqAA) and the [official site](http://www.airspayce.com/mikem/bcm2835/).
~~~
wget  http://www.airspayce.com/mikem/bcm2835/bcm2835-1.55.tar.gz
tar -xvzf bcm2835-1.55.tar.gz
cd bcm2835-1.55.tar.gz
./configure
make
sudo make check
sudo make install
~~~
The version can be updated since 1st of May 2018.

## Dates
March 29:
  - Started this project for fun and to have an extra tool for designing DSP systems.
  - Thought I could do it in 2 weeks, but I soon realized it was a to big of a project.
  - I've made a small test for the click signal, but the Makefile kept not working. So I started reading the Make manual. Did this for the most part of the next two weeks.

April 11th:
  - Thought about what I wanted to do for this project and wrote this in the README.md.
  - Created this LOG.md.

April 14th:
  - Fixed the Makefile. Project compiles now.
  - Makefile still needs to be recursive.

April 16th:
  - Pitched my idea in front of class. Got a green light.
  - Figured some things out about the implicit and pattern rules of Makefiles and the use for them.

April 17th - 20th:
  - Still struggling with the makefile and the project structure I have. I'm turning the Internet upside down in the hopes to find a good example or useful tips. It's hard to think of a way to put the object files in a different repository then the source files and keep the dependencies correct.

April 21st:
  - Because I struggled with the makefile all week, I decided to leave all the object files in the `src/` folder. This way it's still able to compile and keep its dependencies right. I will look later if I'm able to implement the `obj/` folder with correct dependencies, because it should be possible.
  - I looked at the jack_module of Marc, but this is build on Linux and uses some Linux functions like `usleep` and `unistd.h`. Threads also don't work with mingw. I first tried to fix it, like I did with previous projects, but halfway through, I realized that I wanted it to run on a Raspberry Pi and that those edit should be undone then. So I took my old laptop and installed [Elementary OS](https://elementary.io/nl/) on it. That is a Linux distro that looks a lot like Mac OS. I had some trouble installing the programs I needed to code like Atom, Git and JACK. The solutions that worked for me are described at the [top](#installing-programs-on-linux).
  - With JACK working I used an example file from the jack_module to build my main with. This went fairly quickly. I just had to read Marc's code and write some pseudo-code to give me an idea how to do it. Now it works with one minor bug: the first time you fire it doesn't give a click. I will fix this later.

April 23rd:
  - Presentation of progress
  - Discussed the way how to read and write the samples to Jack. Because a static void in the main wasn't very pretty. Marc advised to make a class that has this functionality. When he said that I realized I've done that before in my [Schrodingers Reverb](https://github.com/GeertRoks/CSD2/tree/master/CSD2c/SchrodingersReverb).
  - I created the IO.h and UI.h classes for this.
  - Talked to Pieter Suurmond (DSP Teacher at HKU). He told me I should analyze the impulse response with a FFT.
  - He also told me I best could use a Sweep instead of an [Dirac Pulse](https://en.wikipedia.org/wiki/Dirac_delta_function). This is because the Dirac Pulse is very theoretical and it will generate overshoot in the analog world.

April 25th:
  - Eelco Grimm told me also I shouldn't use a Dirac Pulse, but a sweep. He told me it wasn't really possible and that the Sweep will yield way better results in the real world. He told me I should see the [site of Audio Ease](https://www.audioease.com/altiverb/sampling.php). They have some reference to use the sweep technique for impulse responses.

April 30th:
  - Changed my schedule, because I think having the hardware input and output is way easier than having to test on my computer. Also it's vacation time and working with hardware is something I really like, so I won't mind doing that during my vacation. This way I can do my analysis system next week, since I haven't done anything except asking for advice last week.

May 1st:
  - Installed the BCM2835 library on my Raspberry Pi using this [video](https://www.youtube.com/watch?v=KwSq-WxNqAA) and the [BCM2835 site](http://www.airspayce.com/mikem/bcm2835/).
  - I noticed that jack isn't necessary when using the GPIO pins. I learned from the [Electrosmash site](https://www.electrosmash.com/pedal-pi) that I should use the BCM2835 library. I will follow the instructions on here for now.
  - I tried installing the BCM2835 library on my Linux machine for development, but I get a weird error. So I will see what will be the easiest way to develop. Either writing in Atom on the Linux machine and committing to git and pulling onto the Raspberry Pi, or writing in either Nano or Vim on the Raspberry Pi itself. When using the second option I will have to start using branches to keep updating the LOG and working on the project.

May 2nd:
  - I tried installing vim on my Pi, so I thought I should first update everything (which I now know is wrong). So I did `sudo apt-get update` and then `sudo apt-get upgrade`. It updated about 300 apps and after it was done. 3 couldn't be installed because there was no more room on my sd. Therefore there was no more room for even doing `cd`. Because that makes a temporary file of a few bytes. So I came to the conclusion I needed to install a fresh version of Raspbian. `TODO: add info about how to install Raspbian.`

May 4th:
  - Raspbian Lite didn't work very well. It hasn't standard autologin and SSH isn't enabled automaticly. It seemed a lot of work to find out so I just installed the desktop version, which is just a few minutes of work.
  - I enabled SSH, SPI, I2C and GPIO functionality. Installed bcm2835 library. Rewritten blink sketch. Git cloned HardwareAnalyzer on Pi. Realized that I hadn't committed much, because I never had working code. So I committed my current nonworking code, so it could be pulled to my Raspberry.

May 6th:
  - Got audio working with help of this [video](https://www.youtube.com/watch?v=3pXB90IDNoY). Output circuit is different from the video. I've used the circuit of [Electrosmash](https://www.electrosmash.com/images/tech/pedal-pi/pedal_pi_block_diagram.jpg). Created branches, but not sure if I did it right or in a useful way. [Play sound from usb](https://devtidbits.com/2013/03/21/using-usb-external-hard-disk-flash-drives-with-to-your-raspberry-pi/).

May 7th:
  - Presentation in Class. Asked help for branches.

May 14th:
  - Had nothing to present in class, because I had no progress. Last week was very hectic and there was no time to work on this project.
  - I created the `develop` branch.

May 17th:
  - Initialized the sweep files: sweep.h, sinewave.h and phasor.h. The phasor is going to increase the Pitch of the sinewave in the sweep file.

May 18th:
  - Build the ADC for the Raspberry Pi.
  - I noticed that the sound through the Pi is very muffled. So I started I started calculating the RC filters at the output stage.`TODO: Add info about how I measured the output` I changed the capacitors and that had some improvement, but the sound still  dropped off at 5 KHz. So I think I'll have to change the input capacitors as well.

May 22nd:
  - Tried changing the input capacitors, but it also hadn't much of an effect. It keeps dropping off at 5 KHz. I looked at the [site of Electrosmash](https://www.electrosmash.com/forum/pedal-pi/206-pedal-pi-circuit-analysis) and found that they did that intensionaly, because of harmonics casued by the pwm signal.
  - Installed [KiCAD](http://kicad-pcb.org/). It's a free electronics circuit design program. If there is time I will design a pcb with it as hat for my Raspberry Pi. At {JLCPCB](https://jlcpcb.com/) you can order 10 of these for only $2,-.

 - I lost the overview of my project, because I missed a lot of milestones on my schedule. Also, I have features that work a different way then I intended at first. So I went back to the drawing board. First redrawing my Sweep signal system.
 - Sweep implementation done!. I still need to test it aurally, but the sample points seem right.

May 23rd:
  - I bought 3 MCP4725 DAC boards and a cheap digital oscilloscope (DSO 138) which can analyze signals up to 200 MHz while my analog one only is accurate until 20 MHz. For example the PWM signal of the Pi is too fast for my analog oscilloscope.
  I bought this from [opencircuit.nl](https://opencircuit.nl/). I'm very happy with their shop.

May 25th:
  - Got the package in the mail and directly assembled the oscilloscope, because it's a build it yourself kit.
  - The oscilloscope works wonderful for the price. It has some notable noise, but that doesn't weigh up to all the things you can do with it for only €30,-.

May 27th:
  - Watched this useful [video](https://www.youtube.com/watch?v=PJG79_Yg5Sw). The man in the video explains the MCP4725 and implementation for Raspberry Pi very clearly.
  - I tried it and couldn't get it to work and his video doesn't give any help. I keep getting his `Write to register 1` error. In his video he isn't really clear about what this error does.
  - So I tried using the wiringPi library, because I heard a lot about this. I tried getting it to work with help of [this site](https://engineer.john-whittington.co.uk/2015/03/raspberry-pi-dac-mcp4725-with-wiringpi/). Nonetheless I also didn't get this to work, because I kept getting this error:
  ~~~
  TODO: Add error.
  ~~~
  - After 3 hours of struggling I came to the conclusion that a DIY ADC and DAC is not as simple as I thought it would be and that I needed to pick up my original project. So I decided to use an USB audio interface instead. I think that that is easier to implement and I can use Jack again instead of complicated bit math. I will research this tomorrow.

May 28th:
  - Presented progress in class
  - Discussed my idea about and problems with my DIY ADC and DAC.
  - Discussed my idea about what my deliverable will be and my teachers said that a easily readable report of my research and progress would be a very useful exercise for me. So I will make a report of the research I did about Makefiles, Raspberry Pi and hardware AD/DA converter.
  - In the practicum after class I tried attaching an audio interface to my Raspberry Pi. This also didn't really work and got me a little frustrated.
  - Pieter Suurmond, my DSP teacher, asked me about my progress on my project. He came with the solution to skip the Raspberry Pi for now and just work on an other Linux computer. I completely agreed with him, because that way I can continue on my code and it will still be compatible with a Raspberry Pi if I still want that in the future.

May 29th:
  - With the feedback from yesterday and tip from Pieter Suurmond in mind, I set a goal for today: get the sweep working with JACK on my Linux computer.
  - My first problem was to get Jack working on my Linux computer. I installed it, but always gave me a D-Bus error and that was the moment when I started to develop on the BCM2835 library. I solved this with help of [this site](http://rivendell.tryphon.org/wiki/Debian_6_Installing_JACK2) (See <tag to overview>). `TODO add to overview` JACK and QJackctl worked correctly after that.
  - Then I added jack_module as a submodule again. This gave me some problems, because I didn't fully remove these from the last time. This gave me some path problems that I didn't know to fix. Because I had no local changes, I decided to remove my local project folder and `git clone` it back. That way all modules were gone, because I had removed them on my other computer, but locally it was still stored on my Linux computer. After that I just `git submodule add` the jack_module library from [Marc's github](https://github.com/marcdinkum/) and everything was allright.
  - I didn't want to edit Marc's project folder, because if Marc was to update his library, I would have to re-edit that. Before I called his Makefile recursivly from my Makefile, but that way it compiles also all his examples that I don't want. So I created a module.mk file in the `inc/` folder and added only the jack_module.cpp/.h and ringbuffer.cpp/.h to my Makefile. This works very well.
  - I edited my main.cpp so Jack worked in it. Only leaving the threads out for now. I later want it all in my IO file. I forgot to add the jack.init() and jack.autoConnect() and wondered why I couldn't hear anything and couldn't see my program in the connect list of QJackctl. So be sure to include everything.
  - I debugged some problems in sweep.h that I finally could check.
  - Sweep is still very hardwired and I want it more variable, but that comes later. Also I want the sweep to be logarithmically so the lower frequencies get more attention.
  - For now I want to combine all branches because I made a bit of a mess. Now I know how they work so I think that when I merge my dell branch to the master and remove the rest of the branches I will make better branches this time.

May 30th:
  - Merged the dell branch to master and deleted all branches.
  - Then I created a new develop branch.
  - Something went wrong on my Linux computer with the merging and deleting of branches and it told me I had 18 new commits to be pushed while the remote was allready up to date. So I didn't take the risk and deleted the full project folder and `git clone` it back. All commit problems were solved with this.
  - I noticed that I had no files in the jack_module folder and the program wouldn't compile anymore because of this. I searched how to get the submodule back and read that you have to add it again on [this thread of stackoverflow](https://stackoverflow.com/questions/10054011/git-submodule-not-pulling-files-in-submodules). It says that every time you clone a repository with submodules you have to type this:
  ~~~
  git submodule init
  git submodule update
  ~~~
  This downloads the files back to your computer. If the submodule owner updates his repository, you can pull the changes with `git submodule update`.

May 31st:
  - Tried creating a function that would make the sweep logarithmically.
  - I started with the idea that the input would be between 0 and 2Pi and the output would be between 20 Hz and 20 KHz. I started with the basic logarithmic formula: `F(x) = a * g^x`. Where a is the output at zero and g is the growth factor.
  - When I solved it for the values I wanted and tested it in sweep.h, I thought about making it variable. This was very easy, because a is just the lowest value to be tested. For g you need to solve for `g = log(maxvalue/a) / log(2Pi)`. This is extracted out of the basic formula with F(x) = maxvalue and x = 2Pi.

June 3rd:
  - Checked if the logarithmic sweep is really logarithmic and looked how the linear sweep looks like. They resemble my expectations.
  - From this point I will make a report on my research on the different subjects I came across for my final grade. After that I will finish this project, since it will still be a useful device to have.
