#include <cstdlib>

#include "quiz.hpp"

int quiz_2(const std::vector<int>& numbers) {
    int answer = 0;
    for (int i = 1; i < static_cast<int>(numbers.size()); ++i) {
        const int difference = std::abs(numbers[i] - numbers[i - 1]);
        if (difference > answer) {
            answer = difference;
        }
    }
    return answer;
}
