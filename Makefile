.PHONY: compile submit verify test-template clean

QUIZZES := quizzes/quiz_template quizzes/quiz_001 quizzes/quiz_002

compile:
	for quiz in $(QUIZZES); do $(MAKE) -C $$quiz compile; done

submit:
	for quiz in $(QUIZZES); do $(MAKE) -C $$quiz submit; done

verify:
	for quiz in $(QUIZZES); do $(MAKE) -C $$quiz verify; done

test-template:
	$(MAKE) -C quizzes/quiz_template submit

clean:
	for quiz in $(QUIZZES); do $(MAKE) -C $$quiz clean; done
