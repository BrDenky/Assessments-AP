CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic
LDFLAGS = -pthread

# Include directories for CLI11 and barkeep
INCLUDES = -I/usr/local/include -I/usr/include

# Source files and object files
SRCS = src/main.cpp src/data_analyzer.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = retail_analyzer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean