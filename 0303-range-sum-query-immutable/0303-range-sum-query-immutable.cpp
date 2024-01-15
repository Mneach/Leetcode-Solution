class NumArray {
public:
    
    vector<int> prefixSum;
    
    NumArray(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                prefixSum.push_back(nums[i]);
            }else{
                prefixSum.push_back(prefixSum[i - 1] + nums[i]);
            }
        }
        
    }
    
    int sumRange(int left, int right) {
        
        if(left == 0){
            return prefixSum[right];
        }else{
            int sumRight = prefixSum[right];
            int minus = prefixSum[left - 1];
            
            return sumRight - minus;
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */