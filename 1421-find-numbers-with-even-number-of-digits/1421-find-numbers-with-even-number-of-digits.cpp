class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int answer = 0;
        for (int i = 0; i < nums.size(); i++) {
            int number = nums[i];

            int total = 0;
            while (number > 0) {
                total++;
                number /= 10;
            }

            if (total % 2 == 0) {
                answer++;
            }
        }

        return answer;
    }
};