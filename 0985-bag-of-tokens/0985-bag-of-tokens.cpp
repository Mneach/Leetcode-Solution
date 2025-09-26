/*

How to solve the problem

# Sorting + Two Pointer
1. Sort the tokens
2. initialize two pointer (left = 0 and right = tokens.size() - 1)
3. while (left <= right)
    - if power > tokens[left]
      - decrease the power by tokens[left]
      - increase the score by 1
      - increase left pointer by 1
    - else if current score > 0
      - get the maximum answer -> max(answer, currentScore);
      - increaes the power by the tokens[right]
      - decrease current score by 1

Time Complexity : O(N)
N -> size of tokens

Memory Complexity : O(1)
*/

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int left = 0;
        int right = tokens.size() - 1;
        int answer = 0;
        int currentScore = 0;

        sort(tokens.begin(), tokens.end());

        while (left <= right) {
            if (power >= tokens[left]) {
                power -= tokens[left];
                currentScore += 1;
                answer = max(answer, currentScore);
                left++;
            } else if (currentScore > 0) {
                power += tokens[right];
                currentScore--;
                right--;
            } else {
                break;
            }
        }
        
        return answer;
    }
};