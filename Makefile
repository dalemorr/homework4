#!/bin/make
SHELL = /bin/sh

CXX = g++
CPPFLAGS = -g -Wall
MAIN = main
OBJS = priority_queue.o $(MAIN).o

.PHONY:
	all
	clean

all: clean $(MAIN)

$(MAIN): priority_queue.o $(MAIN).o
	$(CXX) $(CPPFLAGS) -o ./build/$(MAIN) $(OBJS)
	rm -f *.o

$(MAIN).o: priority_queue.o src/main.cc
	$(CXX) $(CPPFLAGS) -c src/$(MAIN).cc

priority_queue.o: src/priority_queue.h src/priority_queue.cc
	$(CXX) $(CPPFLAGS) -c src/priority_queue.cc

clean:
	$(RM) -f core *.o build/main
