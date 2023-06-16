class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0;
        int left  = 0;
        
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) k--;
            
            while(k < 0){
                if(nums[left] == 0) k++;
                left++;
            }
                
            answer = max(answer , right - left + 1 );
        }
        
        return answer;
    }
};