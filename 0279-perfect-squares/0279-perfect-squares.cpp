#include <vector>
#include <unordered_set>
#include <cmath>

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> square_nums;
        for (int i = 1; i * i <= n; ++i) {
            square_nums.push_back(i * i);
        }

        std::unordered_set<int> queue;
        queue.insert(n);

        int level = 0;
        while (!queue.empty()) {
            level += 1;
            std::unordered_set<int> next_queue;

            for (int remainder : queue) {
                for (int square : square_nums) {
                    if (remainder == square) {
                        return level;
                    } else if (remainder < square) {
                        break;
                    } else {
                        next_queue.insert(remainder - square);
                    }
                }
            }
            queue = next_queue;
        }
        return level;
    }
};
