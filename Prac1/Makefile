# Compiler
CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g

# Output executable names
TARGET := TestingMain
DEMO_TARGET := DemoMain

# All .cpp files except mains
COMMON_SRCS := $(filter-out %Main.cpp, $(wildcard *.cpp))
COMMON_OBJS := $(COMMON_SRCS:.cpp=.o)

# Valgrind settings
VALGRIND := valgrind
VGFLAGS  := --leak-check=full --show-leak-kinds=all --track-origins=yes \
            --errors-for-leak-kinds=all --error-exitcode=1

# Build TestingMain
$(TARGET): TestingMain.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build DemoMain
$(DEMO_TARGET): DemoMain.o $(COMMON_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Generic compile rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(TARGET)

demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

run: $(TARGET)
	./$(TARGET)

v: $(TARGET)
	$(VALGRIND) $(VGFLAGS) ./$(TARGET) $(ARGS)

clean:
	rm -f *.o $(TARGET) $(DEMO_TARGET)

rebuild: clean all

.PHONY: all clean rebuild run v demo

