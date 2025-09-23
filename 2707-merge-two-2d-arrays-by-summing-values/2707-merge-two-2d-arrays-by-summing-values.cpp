/*

How to solve the problem 

# Using two pointer technique
1. initialize left and right pointer
2. left = 0 and right = 0
3. if left id > right id
   - push nums2[right] to the answer
   - increase right pointer by 1 
4. if left id < right id
   - push nums1[left] to the answer
   - incrase right pointer by 1
5. if left id == right id, 
   - then add nums1[left] value by nums2[right]
   - add nums1[left] to the answer
   - increase left and right pointer by 1

Time Complexity : O(N + M)
N -> size of nums1
M -> size of nums2

Memory Complexity : O(1)

*/

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> answers;
        int left = 0;
        int right = 0;

        while (left < nums1.size() && right < nums2.size()) {

            if (nums1[left][0] > nums2[right][0]) {
                answers.push_back(nums2[right]);
                right++;
            } else if (nums1[left][0] < nums2[right][0]) {
                answers.push_back(nums1[left]);
                left++;
            } else {
                nums1[left][1] += nums2[right][1];
                answers.push_back(nums1[left]);
                left++;
                right++;
            }
        }

        while (left < nums1.size()) {
            answers.push_back(nums1[left]);
            left++;
        }

        while (right < nums2.size()) {
            answers.push_back(nums2[right]);
            right++;
        }

        return answers;
    }
};