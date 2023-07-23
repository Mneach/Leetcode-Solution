class Solution {
public:
    bool isGood(vector<int>& nums) {
        int maximum = 0;
        
        if(nums.size() == 1) return false;

        sort(nums.begin(), nums.end());       
        
        bool checkSame = false;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1] && i < nums.size() - 2) checkSame = true;    
            maximum = max(maximum, nums[i]);
        }

        if(checkSame == false){
           if(nums.size() == maximum + 1){
               if(nums[nums.size() - 1] == nums[nums.size() - 2]) return true;
               else return false;
           }else{
               return false;
           } 
        }else{
            return false;
        }         
    }
};