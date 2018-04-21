# LOG

##### This is a logbook of the Hardware Analyzer project I'm doing for my Creative Systems Design class at the HKU.

### Current Bugs

- First fire doesn't give a click.

### Fixed Bugs

### Subjects

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

### Dates
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
  - I looked at the jack_module of Marc, but this is build on linux and uses some linux functions like `usleep` and `unistd.h`. Threads also don't work with mingw. I first tried to fix it, like I did with previous projects, but halfway through, I realized that I wanted it to run on a Raspberry Pi and that those edit should be undone then. So I took my old laptop and installed `Elementary OS` on it. That is a linux distro that looks a lot like MacOS. I had some trouble installing the programs I needed to code like Atom, Git and JACK. `The solutions that worked for me are descriped at the top. (link to top?)`
  - With JACK working I used an example file from the jack_module to build my main with. This went fairly quickly. I just had to read Marc's code and write some pseudo-code to give me an idea how to do it. Now it works with one minor bug: the first time you fire it doesn't give a click. I will fix this later.
