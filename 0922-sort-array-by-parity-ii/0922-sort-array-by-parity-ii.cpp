class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
      
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] % 2 != i % 2){
                
                int temp = i;
                
                while(temp < nums.size() && nums[temp] % 2 != i % 2){
                    temp++;
                }
                
                swap(nums[i], nums[temp]);
            }
        }
        
        
        return nums;
    }
};