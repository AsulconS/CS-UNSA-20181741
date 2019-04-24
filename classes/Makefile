CXX			= g++
CXX_FLAGS	= -std=c++11
OBJECTS		= main.o geometry.o sorts.o

all: build trash

build: $(OBJECTS)
	$(CXX) $(CXX_FLAGS) $(OBJECTS) -o main

main.o:
	$(CXX) $(CXX_FLAGS) -c main.cpp

geometry.o: geometry.cpp
	$(CXX) $(CXX_FLAGS) -c geometry.cpp

sorts.o: sorts.cpp
	$(CXX) $(CXX_FLAGS) -c sorts.cpp

trash:
	rm -rf *.o

clean:
	rm -rf *.o main
