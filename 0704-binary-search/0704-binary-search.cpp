class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        
        
        int left = 0;
        int right = nums.size() - 1;
        
        int searchIndex = -1;
        while(left <= right){
            
            int mid = left + (right - left) / 2;
            printf("%d %d %d\n" , left , mid , right);
            if(nums[mid] == target){
                searchIndex = mid;
                break;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }
        }
        
        return searchIndex;
    }
};