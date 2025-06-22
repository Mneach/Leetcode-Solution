class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string> answer;

        string temp = "";
        for (auto c : s) {
            temp += c;

            if (temp.size() == k) {
                answer.push_back(temp);
                temp = "";
            }
        }

        if (temp == "") return answer;

        while(temp.size() != k) {
            temp += fill;
        }

        answer.push_back(temp);

        return answer;
    }
};