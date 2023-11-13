class Solution {
public:
    
    int binarySearch(vector<int>& nums, int left, int right){
        bool recursiveCheck = false;
        if(left <= right){
            int mid = (left + right) / 2;
            if(mid == 0){
               // 10 1
               if(nums[mid] > nums[mid + 1]) return mid;   
               recursiveCheck = true;
            }else if(mid == nums.size() - 1){
               if(nums[mid] > nums[mid - 1]) return mid;
               recursiveCheck = true;
            }else if(nums[mid] >= nums[mid - 1] && nums[mid] >= nums[mid + 1]){
                // 1 2 1
                return mid;
            }else if(nums[mid] <= nums[mid - 1] && nums[mid] <= nums[mid + 1]){
                // 2 1 2
                recursiveCheck = true;
            }else if(nums[mid] <= nums[mid - 1] && nums[mid] >= nums[mid + 1]){
                // 3 2 1
                recursiveCheck = true;
            }else if(nums[mid] >= nums[mid - 1] && nums[mid] <= nums[mid + 1]){
                // 1 2 3
                recursiveCheck = true;
            }
            
            if(recursiveCheck){
                recursiveCheck = false;
                // recursive right
                int recursiveRight = binarySearch(nums, mid + 1 , right);
                // recursive left
                int recursiveLeft = binarySearch(nums, left, mid - 1);
                
                if(recursiveRight != -1){
                    return recursiveRight;
                }else if(recursiveLeft != -1){
                    return recursiveLeft;
                }else{
                    return -1;
                }
            }
        }
        
        return -1;
    }
    
    int findPeakElement(vector<int>& nums) {
       if(nums.size() == 1) return 0;
       if(nums.size() == 2) return nums[0] > nums[1] ? 0 : 1;
        
       return binarySearch(nums, 0, nums.size() - 1);
    }
};