#!/bin/make
SHELL = /bin/sh

CXX = g++
CPPFLAGS = -g -Wall
MAIN = main
OBJS = airport_record.o priority_queue.o $(MAIN).o

.PHONY: all clean

all: clean $(MAIN)

$(MAIN): airport_record.o priority_queue.o $(MAIN).o
	$(CXX) $(CPPFLAGS) -o ./build/$(MAIN) $(OBJS)
	rm -f *.o

$(MAIN).o: airport_record.o priority_queue.o src/main.cc
	$(CXX) $(CPPFLAGS) -c src/$(MAIN).cc

priority_queue.o: src/airport_record.h src/priority_queue.h src/priority_queue.cc
	$(CXX) $(CPPFLAGS) -c src/priority_queue.cc

airport_record.o: src/airport_record.h src/airport_record.cc
	$(CXX) $(CPPFLAGS) -c src/airport_record.cc

clean:
	$(RM) core *.o build/main
