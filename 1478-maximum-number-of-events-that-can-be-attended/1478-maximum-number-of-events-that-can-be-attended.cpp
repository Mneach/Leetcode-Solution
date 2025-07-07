class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int day = 0;
        int index = 0;
        int answer = 0;

        while (index < events.size() || pq.size() > 0) {
            if (pq.size() == 0 && index < events.size()) {
                day = events[index][0];
            }

            while (index < events.size() && events[index][0] <= day) {
                pq.push(events[index][1]);
                index++;
            }

            pq.pop();
            answer++;
            day++;

            while (pq.size() > 0 && pq.top() < day) {
                pq.pop();
            }
        }

        return answer;
    }
};