class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int answer = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            int first = nums[i];
            int second = nums[i + 1];
            int third = nums[i + 2];

            int result = 2 * (first + third);

            if (result == second) {
                answer++;
            }
        }
        
        return answer;
    }
};