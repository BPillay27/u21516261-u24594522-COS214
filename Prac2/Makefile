#Compiler
CX := g++
CXX := -std=c++11 -g

#Output executables
Testing := TestingMain


COMMON_SRCS := $(filter-out %Main.cpp, $(wildcard *.cpp))
COMMON_OBJS := $(COMMON_SRCS:.cpp=.o)

#Valgrind settings
VAL := valgrind
VGFLAGS  := --leak-check=full --show-leak-kinds=all --track-origins=yes --errors-for-leak-kinds=all --error-exitcode=1 -s

%.o: %.cpp
	$(CX) $(CXX) $(CXXFLAGS) -c $<

$(Testing): TestingMain.o $(COMMON_OBJS)
	$(CX) $(CXX) $(CXXFLAGS) -o $@ $^

test: $(Testing)
	./$(Testing)

vt: $(Testing)
	$(VAL) $(VGFLAGS) ./$(Testing) $(ARGS)

gdb:$(Testing)
	gdb ./$(Testing)

clean:
	rm -f *.o $(Testing) core*  vgcore*

