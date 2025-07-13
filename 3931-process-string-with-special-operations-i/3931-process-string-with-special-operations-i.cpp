class Solution {
public:
    string processStr(string s) {
       string answer = ""; 

       for (auto c : s) {
            if (c == '*' && answer.size() > 0) {
                answer.pop_back();
            } else if (c == '#') {
                answer += answer;
            } else if (c == '%'){
                reverse(answer.begin(), answer.end());
            } else if (c >= 'a' && c <= 'z'){
                answer += c;
            }
       }

       return answer;
    }
};