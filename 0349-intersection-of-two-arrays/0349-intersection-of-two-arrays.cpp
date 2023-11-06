class Solution {
public:
    
    bool binarySearch(vector<int> nums1, int left, int right, int target){
        
        while(left <= right){
            int mid = (left + right) / 2;
            
            if(nums1[mid] < target){
                left = mid + 1;
            }else if(nums1[mid] > target){
                right = mid - 1;
            }else{
                return true;
            }
        }
        
        return false;
    }
    
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> result;
        set<int> tempResult;
        sort(nums1.begin(), nums1.end());
        for(int i = 0; i < nums2.size(); i++){
            
            int left = 0;
            int right = nums1.size() - 1;
            
            if(binarySearch(nums1, left, right, nums2[i])){
                tempResult.insert(nums2[i]);
            }
        }
        
        for(auto data : tempResult){
            result.push_back(data);
        }
        
        return result;
    }
};