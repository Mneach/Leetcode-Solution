class Solution {
public:
    
    int binarySearch(vector<int>& nums2, int left, int right, int target){
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(nums2[mid] < target){
                left = mid + 1;
            }else if(nums2[mid] > target){
                right = mid - 1;
            }else{
                return nums2[mid];
            }
        }
        
        return -1;
    }
    
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        for(int i = 0; i < nums1.size(); i++){
            
            int result = binarySearch(nums2, 0, nums2.size() - 1, nums1[i]);
            if(result != -1){
                return result;
            }
        }
        
        return -1;
    }
};