class Solution {
public:
    string reformat(string s) {
        string number = "";
        string character = "";

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                number += c;
            } else {
                character += c;
            }
        }

        int diff = number.length() - character.length();

        if (abs(diff) > 1) return "";

        string answer = "";

        int x = 0;
        int y = 0;
        
        if (number.length() > character.length()) {
            answer += number[x];
            x++;
        } else if (number.length() < character.length()){
            answer += character[y];
            y++;
        }

        while (x < number.size() && y < character.size()) {
            if (x > y) {
                answer += character[y];
                answer += number[x];
            } else {
                answer += number[x];
                answer += character[y];
            }
            
            x++;
            y++;
        }

        return answer;
    }
};