class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int negative = 0;
        int positive = 0;
         
        binary_search(nums, 0 , nums.size() - 1, negative, positive); 
        
        return max(negative, positive);
    }
    
    void binary_search(vector<int> nums , int left, int right, int& negative, int &positive){
        
        if(left > right) return;
        
        int mid = (left + right) / 2;
       
        binary_search(nums, left, mid - 1, negative, positive);
        if(nums[mid] < 0) negative++;
        else if(nums[mid] > 0) positive++;
        binary_search(nums, mid + 1, right, negative, positive);
    }
};