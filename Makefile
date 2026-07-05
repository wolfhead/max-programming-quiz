.PHONY: verify-data test-template clean

CXX ?= g++

verify-data:
	$(CXX) -std=c++17 -Wall -Wextra -pedantic -O2 tools/verify_quiz_001_reference.cpp -o /tmp/verify_quiz_001_reference
	/tmp/verify_quiz_001_reference

test-template:
	$(MAKE) -C quizzes/quiz_template test

clean:
	$(MAKE) -C quizzes/quiz_template clean
	$(MAKE) -C quizzes/quiz_001 clean
	rm -f /tmp/verify_quiz_001_reference
