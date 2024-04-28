class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        int answer = INT_MAX;
        
        for(int i = 0; i < nums1.size(); i++){
            int operation = nums2[0] - nums1[i];
            
            // start the operation
            int counterFalse = 0;
            int pointer2 = 0;
            for(int pointer1 = 0; pointer1 < nums1.size() && pointer2 < nums2.size(); pointer1++){
                if(nums1[pointer1] + operation != nums2[pointer2]){
                    counterFalse++;
                }else{
                    pointer2++;
                }
            }
            
            if(counterFalse <= 2){
                answer = min(answer, operation);
            }
        }
        
        return answer;
    }
};