class Solution {
public:
    int minDifference(vector<int>& nums) {
        if(nums.size() <= 4) return 0;  

        sort(nums.begin(), nums.end());
        int answer = INT_MAX;

        int left = 0;

        for(int i = nums.size() - 4; i < nums.size(); i++){
            answer = min(nums[i] - nums[left], answer);
            left++;
        }


        return answer;
    }
};