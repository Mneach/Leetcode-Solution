class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        if(words.size() == 1) return true;
        
        map<char,int> mp;
        
        for(int i = 0; i < words.size(); i++){
            for(int j = 0; j < words[i].length(); j++){
                mp[words[i][j]]++;
            }
        }
        
        for(auto data : mp){
            if(data.second % words.size() != 0){
                return false;
            }
        }
        
        return true;
    }
};