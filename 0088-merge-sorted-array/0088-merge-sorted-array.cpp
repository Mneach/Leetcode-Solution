/*

How to solve the problem 

# Using Two Pointer
1. we will move from last index in nums1 until first index nums1
   - the reason is because we need to merge nums1 and nums2 data to nums1 array
2. initialize two pointer, left and right pointer, current pointer
3. left = m -1 , and right pointer = n - 1, current pointer nums1.size()
4. loop the current pointer from last index of nums until first index of nums
   - if nums1[left] < nums2[right], 
     - nums1[current] = nums2[right]
     - decrease the right by 1
   - if nums1[left] < nums2[right]
     - nums1[current] = nums1[left];
     - decreaes the left by 1
   - decrease current pointer by 1

Time Complexity : O(N + M)
N -> size of nums1
M -> size of nums2

Memory Complexity : O(1)
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = n - 1;
        int current = nums1.size() - 1;
        
        while (current < nums1.size()) {
            if (left >= 0 && right >= 0) {
                if (nums1[left] >= nums2[right]) {
                    nums1[current] = nums1[left];
                    left--;
                } else {
                    nums1[current] = nums2[right];
                    right--;
                }
            } else if (left >= 0 && right < 0) {
                nums1[current] = nums1[left];
                left--;
            } else if (left < 0 && right >= 0) {
                nums1[current] = nums2[right];
                right--;
            }

            current--;
        }
    }
};