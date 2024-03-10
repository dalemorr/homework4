#!/bin/make
SHELL = /bin/sh

CXX = g++
CPPFLAGS = -g -Wall
MAIN = main
OBJS = priority_queue.o $(MAIN).o

.PHONY: all clean

all: clean $(MAIN)

$(MAIN): src/airport_record.h priority_queue.o $(MAIN).o
	$(CXX) $(CPPFLAGS) -o ./build/$(MAIN) $(OBJS)
	rm -f *.o

$(MAIN).o: src/airport_record.h priority_queue.o src/main.cc
	$(CXX) $(CPPFLAGS) -c src/$(MAIN).cc

priority_queue.o: src/airport_record.h src/priority_queue.h src/priority_queue.cc
	$(CXX) $(CPPFLAGS) -c src/priority_queue.cc

clean:
	$(RM) core *.o build/main
