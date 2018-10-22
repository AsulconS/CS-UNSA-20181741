CC=g++

all: sorts.o geometry.o main.o
	$(CC) sorts.o geometry.o main.o -o main

sorts.o: sorts.cpp
	$(CC) -c sorts.cpp

geometry.o: geometry.cpp
	$(CC) -c geometry.cpp

main.o:
	$(CC) -c main.cpp

clean:
	rm -rf *.o main
