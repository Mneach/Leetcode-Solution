/*

How to solve the problem

# Using Two pointer + Sorting
1. Sort the g and s arrays
2. intialize left and right pointer (left = 0 and right = 0)
3. while g[left] < s[right]
   - increase left pointer by 1
   - increase right pointer by 1
4. return the left pointer

Time Complexity : O(N log N + M log M)
N -> size of g arrays
M -> size of s arrays

Memory Complexity : O(1)

*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int left = 0;
        int right = 0;
        int answer = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (left < g.size() && right < s.size()) {
            if (g[left] <= s[right]) {
                left++;
                right++;
                answer++;
            } else if (g[left] > s[right]) {
                right++;
            }
        }
        
        return answer;
    }
};