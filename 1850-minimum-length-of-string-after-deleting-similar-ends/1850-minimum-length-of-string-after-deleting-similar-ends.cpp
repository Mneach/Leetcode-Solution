/*

How to solve the problem

# Using two pointer technique
1. initialize left and right pointer (left = 0 and right = s.length() - 1)
2. while (left < right)
   - if (s[left] != s[right])
     - break;
   - else 
     - increase left pointer until s[left] != s[left + 1]
     - decrease right pointer until s[right] != s[right - 1]
     - if (left > right) return 0
     - increase left pointer by 1
     - decrease right pointer by 1

Time Complexity : O(N)
N -> length of s

Memory Complexity : O(1)

*/


class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                break;
            } else {
                // move left pointer until nums[left] != nums[left + 1]
                while (left < s.length() - 1 && s[left] == s[left + 1]) {
                    left++;
                }

                // move right pointer until nums[right] != nums[right - 1]
                while (right > 0 && s[right] == s[right - 1]) {
                    right--;
                }

                if (left > right) {
                    return 0;
                }

                left++;
                right--;
            }
        }

        return (right - left) + 1;
    }
};