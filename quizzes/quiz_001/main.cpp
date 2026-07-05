#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "quiz.hpp"

int main() {
    std::ifstream cases("tests/cases.txt");
    if (!cases) {
        std::cerr << "error: cannot open tests/cases.txt\n";
        return 2;
    }

    std::string line;
    int passed = 0;
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
        const int actual = quiz_1(inputA);
        if (actual == expected) {
            ++passed;
            continue;
        }

        std::cerr << "case " << total << " failed: inputA=" << inputA
                  << ", expected=" << expected << ", actual=" << actual << "\n";
    }

    if (passed != total) {
        std::cerr << passed << "/" << total << " tests passed.\n";
        return 1;
    }

    std::cout << "All tests passed. (" << total << "/" << total << ")\n";
    return 0;
}
