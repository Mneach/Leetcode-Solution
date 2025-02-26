class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int total = 0;
        int answer = 0;
        int currentMax = 0;
        int currentMin = 0;

        for (auto data : nums) {
            total += data;
            answer = max({answer, abs(total - currentMax), abs(total - currentMin)});

            currentMax = max({total, currentMax});
            currentMin = min({total, currentMin});
        }

        return answer;
    }
};