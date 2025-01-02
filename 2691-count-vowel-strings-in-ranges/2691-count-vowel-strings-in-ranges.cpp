class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size(), 0);
        vector<int> answer;

        string vowel = "aiueo";

        for (int i = 0; i < words.size(); i++) {

            int first = 0;
            int end = words[i].length() - 1;

            if (vowel.find(words[i][first]) != string::npos && vowel.find(words[i][end]) != string::npos) {
                prefixSum[i]++;
            }

            if (i > 0) prefixSum[i] += prefixSum[i - 1];
        }

        for (auto query : queries) {

            int start = query[0];
            int end = query[1];

            if (start == 0) {
                answer.push_back(prefixSum[end]);
            } else {
                answer.push_back(prefixSum[end] - prefixSum[start - 1]);
            }
        }

        return answer;
    }
};