class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char , char> s_map;
        unordered_map<char , char> t_map;
        
        for(int i = 0; i < s.length(); i++){
            
            if(s_map.count(s[i]) <= 0 && t_map.count(t[i]) <= 0){
                s_map[s[i]] = t[i];
                t_map[t[i]] = s[i];
            }else{
                if(s_map[s[i]] != t[i] && t_map[t[i]] != s[i]) return false; 
            }
        }
        
        
        return true;
    }
    
};