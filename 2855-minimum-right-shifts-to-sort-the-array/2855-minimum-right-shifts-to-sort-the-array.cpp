class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        
       
        int shift = 0;
        
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] > nums[i + 1]){
                shift = nums.size() - (i + 1);
                break;
            }
        }
        
        vector<int> bucket(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            bucket[(shift + i) % nums.size()] = nums[i];
        }
        
        bool isSorted = true;
        for(int i = 0; i < nums.size() - 1; i++){
            cout << bucket[i] << " ";
            if(bucket[i] > bucket[i + 1]){
                isSorted = false;
                break;
            }
        }
        
        if(isSorted){
            return shift;     
        }else{
            return -1;
        }
    }
};