CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJECTS = file.o spec.o monteCarlo1.o monteCarlo2.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
clean:
	$(RM) *.o *.txt main