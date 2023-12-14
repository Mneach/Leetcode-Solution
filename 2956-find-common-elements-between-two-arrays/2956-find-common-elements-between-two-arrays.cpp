class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
        int answer1 = 0;
        int answer2 = 0;
        
        set<int> bucket1(nums1.begin(), nums1.end());
        set<int> bucket2(nums2.begin(), nums2.end());
        
        for(auto data : nums1){
            if(bucket2.count(data)){
                answer1++;
            }
        }
        
        for(auto data : nums2){
            if(bucket1.count(data)){
                answer2++;
            }
        }
        
        return {answer1, answer2};
    }
};