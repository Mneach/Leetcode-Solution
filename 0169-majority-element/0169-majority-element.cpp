class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int majorElement = nums[0];
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(count == 0){
                count++;
                majorElement = nums[i];
            }else if(majorElement == nums[i]){
                count++;
            }else{
                count--;
            }
        }
        
        return majorElement;
    }
};