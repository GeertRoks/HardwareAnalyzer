# LOG

##### This is a logbook of the Hardware Analyzer project I'm doing for my Creative Systems Design class at the HKU.

## Current Bugs

- First fire doesn't give a click.

## Fixed Bugs

## Subjects

#### Make

###### Pattern rules
https://www.gnu.org/software/make/manual/html_node/Pattern-Rules.html


#### Installing programs on LINUX

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
  - I tried installing vim on my Pi, so I thought I should first update everything (which I now know is wrong). So I did `sudo apt-get update` and then `sudo apt-get upgrade`. It updated about 300 apps and after it was done. 3 couldn't be installed because there was no more room on my sd. Therefore there was no more room for even doing `cd`. Because that makes a temporary file of a few bytes. So I came to the conclusion I needed to install a fresh version of Raspbian. `TODO:add info about how to install Raspbian.`

May 4th:
  - `TODO: add more info`. Lite didn't work that well. Autologin, SSH. Installed desktop version. Enabled SSH, SPI, I2C, GPIO. Installed bcm2835 library. Rewritten blink sketch. Git cloned HardwareAnalyzer on Pi. Realized that I hadn't committed that much, because I never had working code. Committed work, so It could be pulled.
