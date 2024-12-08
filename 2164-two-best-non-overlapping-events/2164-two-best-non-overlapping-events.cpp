/*

how to solve : 
1. sort the events by start time
2. alwasy save the maximum value
3. push the overlapping event to the priority queue
4. if the current event is not overlapping, just merge the current event with the prev event

Time complexity : O(N log n)
N log n -> to insert the data into the priority queue 

Memory complexity : O(N)
N -> need priority queue to save the overlapping event

*/

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int answer = 0;

        // time, value
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        sort(events.begin(), events.end());

        int maxValue = 0;
        for (int i = 0; i < events.size(); i++) {
            int start = events[i][0];
            int end = events[i][1];
            int value = events[i][2];

            while (pq.size() > 0 && pq.top().first < start) {
                maxValue = max(maxValue, pq.top().second);
                pq.pop();
            }

            pq.push({end, value});
            answer = max(answer, maxValue + value);
        }

        return answer;
    }
};










