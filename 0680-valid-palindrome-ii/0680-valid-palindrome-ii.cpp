class Solution {
public:
    bool validPalindrome(string s) {
        
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                int leftNext = left + 1;
                int rightNext = right  - 1;

                while (leftNext < right) {
                    if (s[leftNext] == s[right]) {
                        leftNext++;
                        right--;
                    } else {
                        break;
                    }
                }

                while (left < rightNext) {
                    if (s[left] == s[rightNext]) {
                        rightNext--;
                        left++;
                    } else {
                        break;
                    }
                }

                return left >= rightNext || leftNext >= right;
            }
            left++;
            right--;
        }

        return true;
    }
};