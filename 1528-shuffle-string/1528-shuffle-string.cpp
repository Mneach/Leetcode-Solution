class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        
        
        char temp[indices.size()];
        string answer;
        
        for(int i = 0; i < indices.size(); i++){
            temp[indices[i]] = s[i];
        }
        
        for(int i = 0; i < indices.size(); i++){
            answer.push_back(temp[i]);
        }
        
        return answer;
    }
};