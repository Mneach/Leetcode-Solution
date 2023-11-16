class Solution {
public:
    
    int binarySearch(vector<int>& nums, int left, int right){
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(mid == 0){
                cout << nums[mid + 1] << mid << endl;
                if(abs(nums[mid] - nums[mid + 1]) != 1) return nums[mid] + 1;
                else return -1;
            }else if(mid == nums.size() - 1){
                if(abs(nums[mid] - nums[mid - 1]) != 1) return nums[mid] - 1;
                else return -1;
            }else if(abs(nums[mid] - nums[mid + 1]) != 1){
                return nums[mid] + 1;
            }else if(abs(nums[mid] - nums[mid - 1])  != 1){
                return nums[mid] - 1;
            }else {
                int recursiveLeft = binarySearch(nums, left, mid - 1);
                int recursiveRight = binarySearch(nums, mid + 1, right);
                
                if(recursiveLeft != -1){
                    return recursiveLeft;
                }else if(recursiveRight != -1){
                    return recursiveRight;
                }else{
                    return -1;
                }
            }
        }
        
        return -1;
    }
    
    int missingNumber(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0] == 1 ? 0 : 1;
        
        sort(nums.begin(), nums.end());
        
        int result = binarySearch(nums, 0 , nums.size() - 1);
        
        if(result == -1){
            if(nums[0] != 0) return 0;
            else if(nums[0] == 0) return nums.size();
        }else{
            return result;
        }
        
        return result;
    }
};