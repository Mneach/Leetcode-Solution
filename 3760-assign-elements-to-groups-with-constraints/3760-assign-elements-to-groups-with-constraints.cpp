class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        vector<int> answer(groups.size(), -1);
        unordered_map<int,int> bucket;

        for (int i = 0; i < elements.size(); i++) {
            if (bucket.count(elements[i]) > 0) continue;
            bucket[elements[i]] = i;
        }

        for (int i = 0; i < groups.size(); i++) {
            int group = groups[i];

            for (int number = 1; number * number <= group; number++) {

                if (group % number == 0) {
                    int x = number;
                    int y = group / number;

                    if (bucket.count(x) > 0 && answer[i] != -1) {
                        answer[i] = min(answer[i], bucket[x]);
                    } else if (bucket.count(x) > 0) {
                        answer[i] = bucket[x];
                    }

                    if (bucket.count(y) > 0 && answer[i] != -1) {
                        answer[i] = min(answer[i], bucket[y]);
                    } else if (bucket.count(y) > 0) {
                        answer[i] = bucket[y];
                    }
                }
            }
        }

        return answer;
    }
};