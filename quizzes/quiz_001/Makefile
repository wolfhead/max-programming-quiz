CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -O2
TARGET := quiz_test

.PHONY: test clean

test: $(TARGET)
	./$(TARGET)

$(TARGET): main.cpp student/solution.cpp include/quiz.hpp
	$(CXX) $(CXXFLAGS) -Iinclude main.cpp student/solution.cpp -o $(TARGET)

clean:
	rm -f $(TARGET)
