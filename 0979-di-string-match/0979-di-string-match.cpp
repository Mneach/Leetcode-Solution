class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> answer;
        int start = 0;
        int end = s.length();

        for (auto c : s) {
            if (c == 'I') {
                answer.push_back(start);
                start++;
            } else {
                answer.push_back(end); 
                end--;
            }
        }

        answer.push_back(start);

        return answer;
    }
};