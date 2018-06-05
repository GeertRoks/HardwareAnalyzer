# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#  File Name   :   Makefile
#  System Name :   HardwareAnalyzer
#  Version     :   0.1 (not-released)
#  Author      :   Geert Roks
#  GitHub      :   github.com/GeertRoks/HardwareAnalyzer.git
#
#  Function    :   Build system for the program HardwareAnalyzer. It collects
# 	given module.mk files and reads them. From these it creates a list
#	of all relevant source and header files.
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#  For a description of the program and the License see the main.cpp file
#  at src/main.cpp of this project folder. THIS FILE ALSO FALLS UNDER THE
#  LICENSE DESCRIBED IN THE main.cpp FILE.
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#
#  Special thanks to Marc Goenewegen for showing me the module.mk system.
#
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


CXXFLAGS := -Wall -std=c++11
CXXFLAGS += $(patsubst %,-I %, $(MODULES))
LDFLAGS = -I/usr/local/include
LDLIBS = -lpthread -ljack


# the folders where it searches for module.mk files
MODULES := src src/test_signal src/oscillator inc

# each module will add the source files to this
SRC :=

# each module will add the headers to this
HDRS :=

# include the source and header files for each module
include $(patsubst %, %/module.mk, $(MODULES))

# determine the object files
OBJ := $(patsubst %.cpp,%.o, $(SRC))

all: Click

Click: $(OBJ)
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp %.h
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@


# Print Makefile variable function (Makefile debugger)
# 	Type in the commandline: print-<variablename>
#	and it will display whatever <variablename> is.
print-%  : ; @echo $* = $($*)

clean:
	rm $(OBJ)
	rm Click

.PHONY: all clean


# CXX is default g++ so doesn't need to be defined
# $@ is a variable that means the target. (only usable in recipes)
# $< is a variable that means the first prerequisite (only usable in recipes)
# LDFLAGS is for -I and -L and stuff
# LDLIBS is for -lib... and -l... stuff
# % replaces any word
# .PHONY are non-file targets

# $(patsubst pattern,replacement,text)
# Finds whitespace-separated words in text that match pattern and
# replaces them with replacement
#
#  % acts as a wildcard
