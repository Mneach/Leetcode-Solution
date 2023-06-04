class Solution {
public:
    int minimizedStringLength(string s) {
        set<char> answer;
        
        for(int i = 0; i < s.length(); i++){
            answer.insert(s[i]);
        }
        
        return answer.size();
    }
};