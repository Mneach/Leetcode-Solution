class Solution {
public:
    string sortSentence(string s) {
        map<int, string> mp;
        
        string temp = "";
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] >= '0' && s[i] <= '9'){
                mp[s[i] - '0'] = temp;
                temp = "";
            }else if(s[i] != ' '){
                temp += s[i];
            }
            
        }
        
        string answer = "";
        for(auto data : mp){
            answer += data.second;
            answer += " ";
        }
        
        return answer.substr(0, answer.size() - 1);
    }
};