class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if((goal.length() == 1 && s.length() == 1) || s.length() != goal.length()) return false;
        
        if(s == goal){
            unordered_set temp(s.begin(), s.end());
            return temp.size() < s.length();
        } 
        
        vector<int> index;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]){
                index.push_back(i);
            }
        }
        
        if(index.size() != 2) return false;
        
        swap(s[index[0]], s[index[1]]);
        return s == goal;
    }
};