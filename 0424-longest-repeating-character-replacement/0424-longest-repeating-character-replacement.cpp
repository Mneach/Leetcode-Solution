/*

How to solve the problem

# Using sliding window
1. Initialize left, right, bucket of characters, and result
2. while right < s.length()
   - get the ascii character, put that into the bucket
   - get the maximum number and total in the bucket
   - decrease total by maximum number
   - while total > k
     - should move the left pointer and remove the s[left] from the bucket, since this current window is not valid anymore
     - get the maximum number and total in the bucket
     - decrease total by maximum number
   - get the result answer using this formula : result = max(result, right - left + 1)
3. return result

Time Complexity : O(N * M^2)
N -> length of string s
M -> total different characters in the bucket array -> worst case 26 characters

Memory Complexity : O(M)
M -> total different characters in the bucket array

*/


class Solution {
public:
    int characterReplacement(string s, int k) {
        int result = 0;
        vector<int> bucket(26, 0);
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            int ascii = s[right] - 'A';
            bucket[ascii]++;

            int maximum = 0;
            int total = 0;
            for (auto data : bucket) {
                total += data;
                maximum = max(maximum, data);
            }

            total -= maximum;

            while (total > k) {
                bucket[s[left] - 'A']--;
                maximum = 0;
                total = 0;

                for (auto data : bucket) {
                    total += data;
                    maximum = max(maximum, data);
                }
                
                total -= maximum;
                left++;
            }

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};