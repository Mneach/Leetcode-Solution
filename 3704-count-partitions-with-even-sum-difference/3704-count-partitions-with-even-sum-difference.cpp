class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = 0;
        int answer = 0;

        for (auto num : nums) total += num;

        int currentTotal = 0;
        for (auto num : nums) {
            currentTotal += num;
            total -= num;

            if (total == 0) break;

            if ((currentTotal - total) % 2 == 0) {
                answer++;
            }
        }

        return answer;
    }
};