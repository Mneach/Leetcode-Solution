class Solution {
public:
    string reorganizeString(string s) {
        vector<int> bucket(26, 0);

        for (auto c : s) {
            int ascii = c - 'a';
            bucket[ascii]++;
        }

        priority_queue<pair<int,char>> pq;

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] > 0) pq.push({bucket[i], i + 'a'});
        }

        string result = "";
        while (pq.size() > 1) {
            auto [total, curr] = pq.top();
            pq.pop();

            result += curr;
            if (pq.size() >= 1) {
               auto [nextTotal, nextCurr] = pq.top(); 
               pq.pop();

               result += nextCurr;
               if (nextTotal - 1 > 0) {
                    pq.push({nextTotal - 1, nextCurr});
               }
            }

            if (total - 1 > 0) {
                pq.push({total - 1, curr});
            }
        }

        if (pq.size() == 1) {
            auto [total, curr] = pq.top();
            pq.pop();

            if (total == 1) {
                result += curr;
            } else {
                return "";
            }
        }

        return result;
    }
};