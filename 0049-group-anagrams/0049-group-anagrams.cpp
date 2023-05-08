class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int length = strs.size();
        
        vector<vector<string>> answer;
        
        unordered_map<string, vector<string>> temp;
        
        for(int i = 0; i < length; i++){
            
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            temp[strs[i]].push_back(s);
        }
        
        for(auto i : temp){
            answer.push_back(i.second);
        }
        
        return answer;
    }
};