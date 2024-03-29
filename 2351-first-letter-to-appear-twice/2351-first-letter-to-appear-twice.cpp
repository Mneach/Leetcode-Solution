class Solution {
public:
    char repeatedCharacter(string s) {
        map<char,int> mp;
        
        for(int i = 0; i < s.length(); i++){
            mp[s[i]]++;
            if(mp[s[i]] > 1){
                return s[i];
            }
        }
        
        return s[0];
    }
};