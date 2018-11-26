CXX = g++

all: mediator.o ship.o main.o
	$(CXX) mediator.o ship.o main.o -o main

mediator.o: mediator.cpp
	$(CXX) -c mediator.cpp

ship.o: ship.cpp
	$(CXX) -c ship.cpp

main.o: main.cpp
	$(CXX) -c main.cpp

clean:
	rm -rf *.o main
