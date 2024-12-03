class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string answer = "";

        unordered_map<int,int> ump;
        for(auto number : spaces) {
            ump[number]++;
        }

        for (int i = 0; i < s.length(); i++) {
            
            if (ump[i] > 0) {
                answer += " ";
            }

            answer += s[i];
        }

        return answer;
    }
};