class Solution {
public:
    
    bool startsWith(string& str, const string& prefix) {
        if (str.size() < prefix.size()) {
            return false;
        }
        return str.compare(0, prefix.size(), prefix) == 0;
    }

    
    void dfs(string s, vector<string>& wordDict, vector<string>& answer, string current, vector<string> state){
        if(s.length() == current.length()){
            if(s == current){
                
                string res = "";
                for(int i = 0; i < state.size(); i++){
                    res += state[i];
                    
                    if(i != state.size() - 1){
                        res += " ";
                    }
                }
                
                if(res != ""){
                    answer.push_back(res);
                }
            }
            
        }else if(current.length() <= s.length()){
            for(int i = 0; i < wordDict.size(); i++){
                
                if(startsWith(s, current + wordDict[i])){
                    state.push_back(wordDict[i]);
                    dfs(s, wordDict, answer, current + wordDict[i], state);
                    state.pop_back();
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> answer;
        vector<string> state;
        
        dfs(s, wordDict, answer, "", state);
        
        return answer;
    }
};