# KEMI OMONIYI PSET5 11/17/23
#  Makefile
#  CPSC 223 Pset 5
#
#  Makefile for train-conductor.cpp, LinkedList and Station
#


CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
DEPS = Station.h LinkedList.h

train-conductor: train-conductor.o Station.o LinkedList.o
	$(CXX) -o train-conductor train-conductor.o Station.o LinkedList.o

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm -f *.o core* *~ train-conductor
