class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int answer = INT_MAX;
        int totalReplace = 0;
        int left = 0;

        for (int right = 0; right < blocks.size(); right++) {
            char curr = blocks[right];
            int currentTotal = (right - left) + 1;

            if (curr == 'W') {
                totalReplace++;
            }

            if (currentTotal == k) {
                answer = min(answer, totalReplace);
                
                if (blocks[left] == 'W') {
                    totalReplace--;
                }
                left++;
            }
        }

        return answer;
    }
};