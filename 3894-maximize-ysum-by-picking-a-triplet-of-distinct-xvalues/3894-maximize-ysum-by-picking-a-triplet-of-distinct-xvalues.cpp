class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int answer = 0;
        priority_queue<int> pq;
        unordered_map<int,int> bucket;

        for (int i = 0; i < x.size(); i++) {
            if (bucket[x[i]] > 0) {
                bucket[x[i]] = max(bucket[x[i]], y[i]);
            } else {
                bucket[x[i]] = y[i];
            }
        }
        
        for (auto data : bucket) {
            pq.push(data.second);
        }

        int take = 0;
        while(pq.size() > 0) {
            int number = pq.top();
            answer += number;
            pq.pop();
            take++;

            if (take == 3) break;
        }

        if (take < 3) return -1;

        return answer;
    }
};