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

$(MAIN).o: airport_record.o priority_queue.o src/main.cpp
	$(CXX) $(CPPFLAGS) -c src/$(MAIN).cpp

priority_queue.o: src/airport_record.h src/priority_queue.h src/priority_queue.cpp
	$(CXX) $(CPPFLAGS) -c src/priority_queue.cpp

airport_record.o: src/airport_record.h src/airport_record.cpp
	$(CXX) $(CPPFLAGS) -c src/airport_record.cpp

clean:
	$(RM) core *.o build/main
