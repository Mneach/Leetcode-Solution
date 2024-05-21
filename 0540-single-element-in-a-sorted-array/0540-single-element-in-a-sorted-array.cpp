class Solution {
public:
    
    int binarySearch(vector<int> &nums, int left, int right){
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(mid == 0){
                if(nums[mid] != nums[mid + 1]){
                    return nums[mid];
                }else{
                    return -1;
                }
            }else if(mid == nums.size() - 1){
                if(nums[mid] != nums[mid - 1]){
                    return nums[mid];
                }else{
                    return -1;
                }
            }else{
                
                if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]){
                    return nums[mid];
                }
                
                int leftResult = binarySearch(nums, left, mid - 1);
                int rightResult = binarySearch(nums, mid + 1, right);
                
                if(leftResult != -1) return leftResult;
                if(rightResult != -1) return rightResult;
                
                break;
            }
        }
        
        return -1;
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        int left = 0;
        int right = nums.size() - 1;
        
        return binarySearch(nums, left, right);
    }
};