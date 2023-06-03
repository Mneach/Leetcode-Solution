class Solution {
public:
    
    int answer(string s, int index, vector<int>& dp, unordered_map<string, int>& map){
        if(index >= s.length()) return 0;
        if(dp[index] != -1) return dp[index];
        
        string currentString = "";
        int minimumRemove = s.length();
        
        for(int i = index; i < s.size(); i++){
            currentString.push_back(s[i]);
            
            int currentRemove = map.count(currentString) ? 0 : currentString.size();
            int next = answer(s , i + 1, dp , map);
            int total = currentRemove + next;
            
            minimumRemove = min(minimumRemove, total);
        }
        
        return dp[index] = minimumRemove;
    }
        
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length() , -1);
        unordered_map<string, int> map;
        
        for(auto x : dictionary){
            map[x]++;
        }
        
        return answer(s, 0, dp, map);
    }
};




