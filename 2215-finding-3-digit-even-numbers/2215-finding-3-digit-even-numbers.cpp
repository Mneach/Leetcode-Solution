#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    std::vector<int> findEvenNumbers(std::vector<int>& digits) {
        std::unordered_set<int> even_numbers;
        int n = digits.size();

        // Generate all possible 3-digit even numbers with distinct digits
        for (int i = 0; i < n; ++i) {
            // Skip if the first digit would lead to a number less than 100
            if (digits[i] == 0) continue;

            for (int j = 0; j < n; ++j) {
                if (j == i) continue;  // Ensure digits are distinct

                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;  // Ensure digits are distinct
                    if (digits[k] % 2 != 0) continue;  // Last digit must be even

                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    even_numbers.insert(num);
                }
            }
        }

        // Convert the set to a sorted vector
        std::vector<int> result(even_numbers.begin(), even_numbers.end());
        std::sort(result.begin(), result.end());

        return result;
    }
};