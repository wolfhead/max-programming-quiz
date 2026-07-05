#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int reference_quiz_1(int inputA) {
    if (inputA % 2 == 0) {
        return inputA + 2;
    }
    return inputA + 1;
}

int main() {
    std::ifstream cases("quizzes/quiz_001/tests/cases.txt");
    if (!cases) {
        std::cerr << "error: cannot open quizzes/quiz_001/tests/cases.txt\n";
        return 2;
    }

    std::string line;
    int total = 0;

    while (std::getline(cases, line)) {
        if (line.empty() || line[0] == '#') {
            continue;
        }

        std::istringstream input(line);
        int inputA = 0;
        int expected = 0;
        if (!(input >> inputA >> expected)) {
            std::cerr << "error: invalid test case: " << line << "\n";
            return 2;
        }

        ++total;
        const int actual = reference_quiz_1(inputA);
        if (actual != expected) {
            std::cerr << "case " << total << " invalid: inputA=" << inputA
                      << ", expected=" << expected << ", reference=" << actual << "\n";
            return 1;
        }
    }

    std::cout << "Reference checks passed. (" << total << "/" << total << ")\n";
    return 0;
}
