# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude -Iinclude/utils/csv

# Source and object files
SRCDIR = src
UTILDIR = src/utils/csv
INCDIR = include/utils/csv
SRCS = $(wildcard $(SRCDIR)/*.cpp) $(wildcard $(UTILDIR)/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = app

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

