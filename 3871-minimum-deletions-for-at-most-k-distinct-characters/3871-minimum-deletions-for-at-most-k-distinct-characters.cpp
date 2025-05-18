class Solution {
public:
    int minDeletion(string s, int k) {
        int answer = 0;
        int distinct = 0;
        vector<int> bucket(27, 0);

        for (auto c : s) {
            if (bucket[c - 'a'] == 0) distinct++;
            bucket[c - 'a']++;
        }

        sort(bucket.begin(), bucket.end());

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] == 0) continue;

            if (distinct == k) break;
    
            answer += bucket[i];
            distinct--;
        }

        if (distinct != k) return 0;

        return answer;
    }
};