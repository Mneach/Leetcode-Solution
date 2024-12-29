#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxLeft = values[0] + 0; // Maximum value of values[i] + i so far
        int maxScore = 0;

        for (int j = 1; j < values.size(); ++j) {
            // Calculate the potential score with the current maxLeft and values[j] - j
            maxScore = max(maxScore, maxLeft + values[j] - j);

            // Update maxLeft to include the current values[j] + j
            maxLeft = max(maxLeft, values[j] + j);
        }

        return maxScore;
    }
};