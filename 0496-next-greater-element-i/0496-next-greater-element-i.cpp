class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answer;

        for (int i = 0; i < nums1.size(); i++) {
            int number = nums1[i];

            int index = 0;
            for (int i = 0; i < nums2.size(); i++) {
                if (number == nums2[i]) {
                    index = i;
                    break;
                }
            }

            int result = -1;
            for (int j = index + 1; j < nums2.size(); j++) {
                if (nums2[index] < nums2[j]) {
                    result = nums2[j];
                    break;
                }
            }

            answer.push_back(result);
        }

        return answer;
    }
};