CXX = g++
CXXFLAGS = -std=c++11 -Wall -O2
LDFLAGS =

# Object files
OBJS = main.o Parser.o Solver.o

# Executable name
EXEC = knapsack_solver

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)

main.o: main.cpp Parser.h Solver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Parser.o: Parser.cpp Parser.h
	$(CXX) $(CXXFLAGS) -c Parser.cpp

Solver.o: Solver.cpp Solver.h
	$(CXX) $(CXXFLAGS) -c Solver.cpp

clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean
