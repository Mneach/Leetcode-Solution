class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        vector<int> answer;

        for (int i = 0; i < arr.size(); i++) {
            pq.push({arr[i], i});
        }

        for (int i = 0; i < arr.size(); i++) {

            while(pq.size() > 0 && i >= pq.top().second && arr[i] >= pq.top().first) {
                pq.pop();
            }

            if (pq.size() > 0) {
                answer.push_back(pq.top().first);
            } else {
                answer.push_back(-1);
            }
        }

        return answer;
    }
};