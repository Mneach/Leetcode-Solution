class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        long long int sum = 0;
        long long int minimumDecrease = LLONG_MAX;
        int totalXor = 0;
        
        for(auto data : nums){
            long long int operation = data ^ k;
            
            if(operation > data){
                // operation greater than data or nums[i] greater  
                // so we need to check the minimum decrease with formula
                // data - operation
                sum += operation;
                minimumDecrease = min(minimumDecrease, operation - data);
                totalXor++;
            }else{
                // data or nums[i] greater than operation
                // so we need to check the minimum decrease with formula
                // data - operation
                sum += data;
                minimumDecrease = min(minimumDecrease, data - operation);
            }
            
        }
        
        // if total xor operation modulo 2 is equal to 1
        // we cant take sum as the result
        // because there is a sacrifice node (decreasing node because of operation)
        // so we need to decrease the sum by minimumDecrease
        
        if(totalXor % 2 == 1) {
            sum -= minimumDecrease;
        }
        
        return sum;
    }
};