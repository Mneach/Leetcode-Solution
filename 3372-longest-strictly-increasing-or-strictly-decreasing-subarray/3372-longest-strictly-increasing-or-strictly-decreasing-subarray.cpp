class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int answer = 1;
        // search for increasing
        
        int left = 0;
        for(int right = 1; right < nums.size(); right++){
            if(nums[right - 1] < nums[right]){
                answer = max(right - left + 1, answer);
            }else{
                left = right;
            }
        }
        
        // serach for descreasing
        left = 0;
        for(int right = 1; right < nums.size(); right++){
            if(nums[right - 1] > nums[right]){
                answer = max(right - left + 1, answer);
            }else{
                left = right;
            }
        }
        
        return answer;
    }
};