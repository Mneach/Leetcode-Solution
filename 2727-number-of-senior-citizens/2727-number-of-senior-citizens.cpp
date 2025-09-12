/*

How to solve the problem : 
1. start loop from index 11 until detail.length() - 2
   - the reason is because of age start from index 11 and will end in index (detail.length() - 2)
2. calculate the age using this formula
   - age = (age * multiply * 10) + (detail[i] - '0')
Time Complexity : O(N)
N -> length between index 11 until detail.length() - 2

Memory Complexity : O(1)

*/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int answer = 0;

        for (auto detail : details) {
            int age = 0;
            int multiply = 0;
            for (int i = 11; i < detail.length() - 2; i++) {
                age = (age * multiply * 10) + (detail[i] - '0');
                multiply++;
            }

            if (age > 60) answer++;
        }

        return answer;
    }
};