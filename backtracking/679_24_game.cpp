#include <vector>
#include <cmath>
#include <numeric>

class Solution {
private:
    struct Result {
        double value;
        Result fmap(double (*op)(double, double), const Result& other) const {
            return { op(this->value, other.value) };
        }
    };

    std::vector<double> generatePossibilities(double a, double b) {
        std::vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (std::abs(a) > 1e-9) {
            results.push_back(b / a);
        }
        if (std::abs(b) > 1e-9) {
            results.push_back(a / b);
        }
        return results;
    }

    bool canReach24(std::vector<double>& numbers) {
        if (numbers.size() == 1) {
            return std::abs(numbers[0] - 24.0) < 1e-6;
        }

        for (size_t i = 0; i < numbers.size(); ++i) {
            for (size_t j = i + 1; j < numbers.size(); ++j) {
                std::vector<double> remaining_numbers;
                for (size_t k = 0; k < numbers.size(); ++k) {
                    if (k != i && k != j) {
                        remaining_numbers.push_back(numbers[k]);
                    }
                }

                for (double result : generatePossibilities(numbers[i], numbers[j])) {
                    remaining_numbers.push_back(result);
                    if (canReach24(remaining_numbers)) {
                        return true;
                    }
                    remaining_numbers.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(std::vector<int>& cards) {
        std::vector<double> double_cards(cards.begin(), cards.end());
        return canReach24(double_cards);
    }
};
