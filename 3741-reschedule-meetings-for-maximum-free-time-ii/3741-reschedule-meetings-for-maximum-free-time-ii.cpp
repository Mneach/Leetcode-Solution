class Solution {
public:
    int maxFreeTime(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
    int n = startTime.size();
    vector<int> gaps;

    // Calculate free time gaps between events
    gaps.push_back(startTime[0]);
    for (int i = 1; i < n; ++i)
        gaps.push_back(startTime[i] - endTime[i - 1]);
    gaps.push_back(eventTime - endTime.back());

    int m = gaps.size();
    vector<int> maxRightGap(m, 0);

    // Precompute the largest gap to the right of each position
    for (int i = m - 2; i >= 0; --i)
        maxRightGap[i] = max(maxRightGap[i + 1], gaps[i + 1]);

    int maxGap = 0;
    int maxLeftGap = 0;

    for (int i = 1; i < m; ++i) {
        int currentDuration = endTime[i - 1] - startTime[i - 1];
        int maxSurroundingGap = max(maxLeftGap, maxRightGap[i]);

        // Case 1: Can place the event between two gaps
        if (currentDuration <= maxSurroundingGap)
            maxGap = max(maxGap, gaps[i - 1] + currentDuration + gaps[i]);

        // Case 2: Just sum two adjacent gaps
        maxGap = max(maxGap, gaps[i - 1] + gaps[i]);

        // Update max left gap
        maxLeftGap = max(maxLeftGap, gaps[i - 1]);
    }

    return maxGap;
}
};