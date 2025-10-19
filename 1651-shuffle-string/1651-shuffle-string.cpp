class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string answer(s.length(), ' ');
        
        for(int i = 0; i < s.length(); i++){
            answer[indices[i]] = s[i];
        }
        
        return answer;
    }
};