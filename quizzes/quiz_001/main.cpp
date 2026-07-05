#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <sys/resource.h>
#include <ctime>

#include "quiz.hpp"

namespace {

long long current_memory_kb() {
    rusage usage{};
    if (getrusage(RUSAGE_SELF, &usage) != 0) {
        return -1;
    }
#ifdef __APPLE__
    return usage.ru_maxrss / 1024;
#else
    return usage.ru_maxrss;
#endif
}

}  // namespace

int main() {
    const std::clock_t start = std::clock();

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
        const double elapsed_ms =
            1000.0 * static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        std::cerr << "Verdict: Wrong Answer\n";
        std::cerr << "Passed: " << passed << "/" << total << "\n";
        std::cerr << "Time: " << std::fixed << std::setprecision(3) << elapsed_ms << " ms\n";
        std::cerr << "Memory: " << current_memory_kb() << " KB\n";
        return 1;
    }

    const double elapsed_ms =
        1000.0 * static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
    std::cout << "Verdict: Accepted\n";
    std::cout << "Passed: " << passed << "/" << total << "\n";
    std::cout << "Time: " << std::fixed << std::setprecision(3) << elapsed_ms << " ms\n";
    std::cout << "Memory: " << current_memory_kb() << " KB\n";
    return 0;
}
