CXX = g++
CXXFLAGS = -Wall -Wextra

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

TARGET = simple-blockchain

$(TARGET): $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
		rm -f $(OBJECTS) $(TARGET)

