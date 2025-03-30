class Solution {
public:
    int reverseDegree(string s) {
        int answer = 0;
        unordered_map<int,int> ump;
        int start = 26;

        for (int i = 0; i < 26; i++) {
            ump[i + 'a'] = start;
            start--;
        }

        for (int i = 0; i < s.length(); i++) {
            answer += (i + 1) * ump[s[i]];
        }

        return answer;
    }
};