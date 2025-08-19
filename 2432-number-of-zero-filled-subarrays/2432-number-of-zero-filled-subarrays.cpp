class Solution {
public:

    long long calculate(long long total) {
        return (total * (total + 1)) / 2;
    }

    long long zeroFilledSubarray(vector<int>& nums) {
        long long answer = 0;
        long long count = 0; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                count++;
            } else {
                answer += calculate(count);
                count = 0;
            }
        }

        if (count != 0) {
            answer += calculate(count);
        }

        return answer;
    }
};