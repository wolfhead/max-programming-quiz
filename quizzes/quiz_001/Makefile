CXX ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -pedantic -O2
BUILD_DIR := .build
SUBMIT_TARGET := $(BUILD_DIR)/submit
VERIFY_TARGET := $(BUILD_DIR)/verify

.PHONY: compile submit verify test clean

compile: $(SUBMIT_TARGET)

submit: $(SUBMIT_TARGET)
	./$(SUBMIT_TARGET)

verify: $(VERIFY_TARGET)
	./$(VERIFY_TARGET)

test: submit

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(SUBMIT_TARGET): main.cpp student/solution.cpp include/quiz.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -Iinclude main.cpp student/solution.cpp -o $(SUBMIT_TARGET)

$(VERIFY_TARGET): main.cpp reference/solution.cpp include/quiz.hpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -Iinclude main.cpp reference/solution.cpp -o $(VERIFY_TARGET)

clean:
	rm -rf $(BUILD_DIR)
