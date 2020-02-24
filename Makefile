CXX = g++
CXXFLAGS = -g -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = Customer.hpp Queue.o

main: $(OBJECTS) main.o
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf main.o
	$(RM) *.o *.gc* test/*.o test/*.gc* *.dSYM test/test core main