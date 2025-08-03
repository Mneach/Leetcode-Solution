class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int sum = 0;
        int max_fruits = 0;
        const int n = fruits.size();

        // Lambda to calculate the minimum steps needed to cover the current window
        auto calculateSteps = [&](int left, int right) -> int {
            int leftPos = fruits[left][0];
            int rightPos = fruits[right][0];

            if (rightPos <= startPos) {
                return startPos - leftPos;
            } else if (leftPos >= startPos) {
                return rightPos - startPos;
            } else {
                return min(startPos - leftPos, rightPos - startPos) + (rightPos - leftPos);
            }
        };

        for (int right = 0; right < n; ++right) {
            sum += fruits[right][1];
            
            // Shrink the window from the left if the current window exceeds k steps
            while (left <= right && calculateSteps(left, right) > k) {
                sum -= fruits[left][1];
                ++left;
            }
            
            max_fruits = max(max_fruits, sum);
        }
        
        return max_fruits;
    }
};