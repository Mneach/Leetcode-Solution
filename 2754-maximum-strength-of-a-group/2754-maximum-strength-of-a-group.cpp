class Solution {
public:
    
    long long maxLL(long long a , long long b) {
        if(a > b) return a;
        else return b;
    }
    
    long long maxStrength(vector<int>& nums) {
        
        long long positiveResult = LONG_LONG_MIN;
        long long negativeResult = 0;
        
        vector<int> arr;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                arr.push_back(nums[i]);
            }else if(nums[i] == 0 && positiveResult == LONG_LONG_MIN){
                positiveResult = nums[i];
            }else if(nums[i] > 0){
                if(positiveResult == 0 || positiveResult == LONG_LONG_MIN) positiveResult = nums[i];
                else positiveResult *= nums[i];
            }

        }
        
        int length = arr.size();
        if(length % 2 == 1 && length != 1) length--;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < length; i++){
            if(i == 0) negativeResult = arr[i];
            else negativeResult *= arr[i];
        }
        
        if(positiveResult == LONG_LONG_MIN) return negativeResult;
        else return maxLL(positiveResult, maxLL(negativeResult, positiveResult * negativeResult));
    }
};