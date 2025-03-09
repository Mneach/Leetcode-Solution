class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int answer = 0;
        int left = 0;
        int right = 0;
        int current = -1;
        while (left < colors.size()) {
            int color = colors[right % colors.size()];    

            if (current == color) {
                left = right;
            } else {
                int range = (right - left) + 1;

                if (range >= k) {
                    answer++;
                    left++;
                }
            }
            current = color;
            right++;
        }

        return answer;
    }
};