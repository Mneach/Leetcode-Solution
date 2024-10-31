class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int k = costs[0].size();
        int n = costs.size();

        // Initialize variables to track the minimum and second minimum costs.
        int prevMin = -1, prevSecondMin = -1, prevMinColor = -1;
        
        // Find the two lowest costs in the first row, along with the color of the minimum cost.
        for (int color = 0; color < k; color++) {
            int cost = costs[0][color];
            if (prevMin == -1 || cost < prevMin) {
                prevSecondMin = prevMin;
                prevMinColor = color;
                prevMin = cost;
            } else if (prevSecondMin == -1 || cost < prevSecondMin) {
                prevSecondMin = cost;
            }
        }

        // Iterate over each house and calculate the minimum costs for each row.
        for (int house = 1; house < n; house++) {
            int min = -1, secondMin = -1, minColor = -1;
            for (int color = 0; color < k; color++) {
                // Calculate the cost for the current color.
                int cost = costs[house][color];
                if (color == prevMinColor) {
                    cost += prevSecondMin;
                } else {
                    cost += prevMin;
                }
                
                // Update the minimum and second minimum costs.
                if (min == -1 || cost < min) {
                    secondMin = min;
                    minColor = color;
                    min = cost;
                } else if (secondMin == -1 || cost < secondMin) {
                    secondMin = cost;
                }
            }
            // Set the current mins as the previous mins for the next iteration.
            prevMin = min;
            prevSecondMin = secondMin;
            prevMinColor = minColor;
        }

        return prevMin;
    }
};
