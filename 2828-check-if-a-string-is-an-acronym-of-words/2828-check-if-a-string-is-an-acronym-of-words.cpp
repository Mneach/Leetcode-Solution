class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        
        string temp = "";
        for(int i = 0; i < words.size(); i++){
           temp += words[i][0]; 
        } 
        
        return temp == s;
    }
};