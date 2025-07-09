class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int answer = 0; 
        int total = 0;

        for (int i = 0; i < startTime.size(); i++) {
            total += (endTime[i] - startTime[i]); 
            int left, right;
            if (i <= k - 1) {
                left = 0;
            } else {
                left = endTime[i - k];
            }

            if (i == startTime.size() - 1) {
                right = eventTime;
            } else {
                right = startTime[i + 1];
            }

            answer = max(answer, right - left - total);

            if (i >= k - 1) {
                total -= (endTime[i - k + 1] - startTime[i - k + 1]);
            }
        }

        return answer;
    }
};