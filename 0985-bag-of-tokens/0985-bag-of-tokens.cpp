/*

How to solve the problem

# Sorting + Two Pointer
1. Sort the tokens
2. initialize two pointer (left = 0 and right = tokens.size() - 1)
3. while (left <= right)
    - while power > tokens[left]
      - decrease the power by tokens[left]
      - increase the score by 1
      - increase left pointer by 1
    - if current score > 0
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
            while (left <= right && power >= tokens[left]) {
                power -= tokens[left];
                left++;
                currentScore++;
            }

            if (currentScore > 0) {
                answer = max(answer, currentScore);
                power += tokens[right];
                currentScore--;
                right--;
            }

            if (left > right) {
                break;
            } else if (power < tokens[left] && currentScore == 0) {
                break;
            }
        }
        
        return answer;
    }
};