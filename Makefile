CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

OBJECTS = 	main.o

main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	
clean:
	$(RM) *.o *.txt main