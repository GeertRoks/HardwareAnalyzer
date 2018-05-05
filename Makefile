CXXFLAGS := -Wall -std=c++11
CXXFLAGS += $(patsubst %,-I %, $(MODULES))
LDFLAGS = -L"C:/Program Files (x86)/Jack/lib"
LDLIBS = -ljack -lpthread

# -mwindows -I/inc/mingw-std-threads/

# Which subdirs do we want to scan for module.mk ?
MODULES := src src/test_signal src/IO


# each module will add to this
# We'll start with the module in this dir which contains main()
SRC :=

# each module will add the headers that matter to the global project
INCS :=

# include the description for each module
#
include $(patsubst %, %/module.mk,$(MODULES))

# determine the object files
OBJ := $(patsubst %.cpp,%.o, $(SRC))
JACKOBJ = inc/jack_module/ringbuffer.o inc/jack_module/jack_module.o

all: Click

Click: $(OBJ) jack
	$(CXX) -o $@ $(CXXFLAGS) $(OBJ) $(JACKOBJ) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

jack: $(JACKOBJ)
	cd inc/jack_module && $(MAKE) jack_test

print-%  : ; @echo $* = $($*)

clean:
	rm obj/*.o
	rm Click.exe

.PHONY: all clean jack


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
