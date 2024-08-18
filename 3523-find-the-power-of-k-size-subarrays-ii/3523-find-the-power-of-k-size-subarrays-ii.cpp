class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> answer(nums.size() - (k - 1), -1);

        if(nums.size() == 1) {
            answer[0] = nums[0];
            return answer;
        }else if(k == 1){
            return nums;
        }

        int left = 0;
        
        for(int right = 1; right < nums.size(); right++){
            
            if(nums[right] - nums[left] == right - left){
                if(right - left >= k - 1){
                    answer[left] = nums[right];
                    left++;
                }
            }else{
                left = right;
            }
        }

        return answer;
    }
};