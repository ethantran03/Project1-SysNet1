CXX = g++
CXXFLAGS = -Wall -g

myshell: myshell.o param.o parse.o
	$(CXX) $(CXXFLAGS) -o myshell myshell.o param.o parse.o

myshell.o: myshell.cpp param.hpp parse.hpp
	$(CXX) $(CXXFLAGS) -c myshell.cpp

param.o: param.cpp param.hpp
	$(CXX) $(CXXFLAGS) -c param.cpp

parse.o: parse.cpp param.hpp parse.hpp
	$(CXX) $(CXXFLAGS) -c parse.cpp

clean:
	rm -f myshell *.o
