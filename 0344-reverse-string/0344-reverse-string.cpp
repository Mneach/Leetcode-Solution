/*

How to solve the problem : 

# Using Two Pointer Technique
1. Initiallize left pointer and right pointer
2. left = 0 and right = s.lenght () -1; 
3. looping while left < right, then swap s[left] with s[right]
4. increase left pointer and decrease right pointer by 1

Time Complexity : O(N)
N -> size of S

Memory Complexity : O(1)

*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;        
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};