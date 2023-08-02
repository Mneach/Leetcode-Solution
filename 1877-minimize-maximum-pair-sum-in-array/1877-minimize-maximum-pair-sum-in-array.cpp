class Solution {
public:
    int minPairSum(vector<int>& nums) {
       
        sort(nums.begin(), nums.end());
        
        int answer = 0;
        int left = 0;
        int right = nums.size() - 1;
        
        for(int i = 0; i < nums.size() / 2; i++){
            answer = max(nums[left] + nums[right] , answer);
            left++;
            right--;
        }
        
        
        return answer;
    }
};