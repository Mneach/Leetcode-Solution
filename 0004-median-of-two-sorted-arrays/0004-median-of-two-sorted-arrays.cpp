/*

Approach 1 : Using binary search approach
1. Find the symetric by using binary search
2. If total size of nums is odd, then use this formula to get the answer max (l1, l2)
3. If total size of nums is even, then use this formula to get the answer (max(l1, l2) + min(r1, r2)) / 2

Example : 
nums1 = [5,7,10,20,30,40]
nums2 = [10,20,30,40,50,60,70,80]
total = 13 -> odd, then use this formula max (l1, l2)

we will use the array that has smallest size, which is nums1

process 1 : 
left = 0;
right = 6
mid = 3

take 2 number from nums 1 and take 4 number from nums 2
5,7(l1)         | 20(r1), 30, 40
10,20,30,40(l2) | 40(r2), 50, 60, 70, 80

compare l1 with r2 = 7 < 40, true
compare l2 with r1 = 40 < 20, false

because there is a false condition, then we need to move left pointer to mid + 1

process 2 :
left = 4
right = 6
mid = 5

take 4 number from nums 1 and take 2 number from nums 2
5,7,10,20,30(l1) | 40(r2)
10,20(l2)        | 30(r2), 40, 50, 60, 70, 80

because total is odd, then we use this formula max(l1, l2)
result = 30
*/


class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        if (nums1.size() == 0) {
            int size = nums2.size();
            if (size % 2 == 0) {
                return 1.0 * (nums2[size / 2] + nums2[(size / 2) - 1]) / 2; 
            } else {
                return 1.0 * nums2[size / 2];
            }
        }

        int total = nums1.size() + nums2.size();
        int take = total / 2;
        int left = 0;
        int right = nums1.size();

        while (left <= right) {
            int mid = (left + right) / 2;
            int remaining = ((nums1.size() + nums2.size() + 1) / 2) - mid;

            int l1 = mid == 0 ? INT_MIN : nums1[mid - 1];
            int r1 = mid == nums1.size() ? INT_MAX : nums1[mid];
            
            int l2 = remaining == 0 ? INT_MIN : nums2[remaining - 1];
            int r2 = remaining == nums2.size() ? INT_MAX : nums2[remaining];

            if (l1 <= r2 && l2 <= r1) {
                if ((nums1.size() + nums2.size()) % 2 == 1) {
                    return 1.0 * (max(l1, l2));
                } else {
                    return 1.0 * (max(l1, l2) + min(r1, r2)) / 2;
                }
            } else {
                if (l2 > r1) {
                    left = mid + 1;
                } else if (l1 > r2) {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};