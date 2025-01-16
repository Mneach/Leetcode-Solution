class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        
        int y = 0;

        for (auto num : nums2) y ^= num;

        int answer = 0;
        for (int i = 0; i < nums1.size(); i++) {

            int x = nums1[i];
            
            if (nums2.size() % 2 == 0) {
                x = 0;
            }
            
            answer ^= (x ^ y);
        }


        return answer;
    }
};