# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRCS = main.cpp LinkedList.cpp
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = project

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp LinkedList.hpp Node.hpp
LinkedList.o: LinkedList.cpp LinkedList.hpp Node.hpp

clean:
	rm -f *.o $(TARGET)

run: $(TARGET)
	./$(TARGET)
