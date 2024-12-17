class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char,int>> pq;
        unordered_map<char,int> ump;
        string answer = "";
        
        for (auto c : s) {
            ump[c]++;
        }

        for (auto data : ump) {
            pq.push({data.first, data.second});
        }

        while (pq.size() > 0){ 
            
            auto [c, total] = pq.top();

            pq.pop();
            
            int count = 0;

            while (count < repeatLimit) {
                answer += c;
                total--;
                count++;

                if (total == 0) break;
            }

            if (pq.size() > 0 && total > 0) {
                auto [nextC, nextTotal] = pq.top();
                pq.pop();

                answer += nextC;
                nextTotal--;

                if (nextTotal > 0) {
                    pq.push({nextC, nextTotal});
                }
            }

            if (total > 0) {
                pq.push({c, total});
            }
        }

        // cut last repeated character 

        int count = 0;
        int index = -1;
        for (int i = 0; i < answer.length() - 1; i++) {
            if (answer[i] == answer[i + 1]) {
                count++;
            } else {
                count = 0;
            }
            
            if (count == repeatLimit) index = i;
        }

        if (index == -1) return answer;
        else return answer.substr(0, index + 1);
    }
};