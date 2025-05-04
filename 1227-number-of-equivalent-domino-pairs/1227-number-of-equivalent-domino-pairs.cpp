class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int answer = 0;
        vector<int> preCompute(dominoes.size() + 1, 0);
        vector<vector<int>> bucket(10, vector<int>(10, 0));

        for (int i = 2; i < preCompute.size(); i++) {
            preCompute[i] = preCompute[i - 1] + i - 1; 
        }

        for (auto domino : dominoes) {
            int first = domino[0];
            int second = domino[1];

            bucket[min(first, second)][max(first, second)]++;
        }

        for (int i = 1; i < bucket.size(); i++) {
            for (int j = 1; j < bucket[i].size(); j++) {
                answer += preCompute[bucket[i][j]];
            }
        }

        return answer;
    }
};