class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> answer;
        unordered_map<int,int> bucket;
        unordered_map<int,int> ump;

        for (auto query : queries) {
            int number = query[0];
            int color = query[1];

            if (bucket[number] > 0) {
                ump[bucket[number]]--;

                if (ump[bucket[number]] == 0) {
                    ump.erase(bucket[number]);
                }
            }

            bucket[number] = color;
            ump[color]++;
            answer.push_back(ump.size());
        }

        return answer;
    }
};