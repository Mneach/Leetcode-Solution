class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int answer = 0;
        
        int l = 0;
        int totalZero = 0;
        for(int r = 0; r < nums.size(); r++){
            if(nums[r] == 0) totalZero++;
            
            while(totalZero > k){
                if(nums[l] == 0) totalZero--;
                l++;
            }
                
            answer = max(answer , r - l + 1 );
        }
        
        return answer;
    }
};