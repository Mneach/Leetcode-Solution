class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        vector<int> arr(1001, 0);
        
        int answer = nums.size();
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i]]++;
        }
        
        for(int i = 999; i >= 0; i--){
            arr[i] += arr[i + 1];
        }
        
        for(int i = 0; i <= 1000; i++){
            if(i == arr[i]){
                return i;
            }
        }
        
        return -1;
    }
};