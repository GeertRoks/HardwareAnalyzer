GXX = g++
CFLAGS = -Wall -std=c++11
LDFLAGS =

all: click.o main.o
	mv *.o obj/
	$(GXX) $(CFLAGS) -o Click obj/*.o

main.o: src/main.cpp
	$(GXX) $(CFLAGS) -c src/main.cpp


click.o: src/test_signal/click.cpp src/test_signal/click.h
	$(GXX) $(CFLAGS) -c src/test_signal/click.cpp

clean:
	rm obj/*.o
