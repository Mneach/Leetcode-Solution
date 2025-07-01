class Solution {
public:
    int possibleStringCount(string word) {
        int answer = 0;
        int left = 0;
        int right = 0;

        while (right < word.size()) {
            if (word[right] != word[left]) {
                answer += (right - left) - 1;
                left = right;
            }
            
            right++;
        }

        answer += (right - left);

        return answer;
    }
};