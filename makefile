CXX = g++
CXXFLAGS = -g -Wall

all: myshell

myshell: myshell.o parse.o param.o
	$(CXX) $(CXXFLAGS) -o myshell myshell.o parse.o param.o

myshell.o: myshell.cpp parse.hpp param.hpp
	$(CXX) $(CXXFLAGS) -c myshell.cpp

parse.o: parse.cpp parse.hpp
	$(CXX) $(CXXFLAGS) -c parse.cpp

param.o: param.cpp param.hpp
	$(CXX) $(CXXFLAGS) -c param.cpp

clean:
	rm -f *.o myshell
