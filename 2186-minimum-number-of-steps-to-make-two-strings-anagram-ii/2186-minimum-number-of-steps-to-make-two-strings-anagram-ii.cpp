class Solution {
public:
    int minSteps(string s, string t) {
        
        unordered_map<int,int> ump;
        
        for(int i = 0; i < s.length(); i++){
            ump[s[i]]++;
        }
        
        for(int i = 0; i < t.length(); i++){
            ump[t[i]]--;
        }
        
        int answer = 0;
        for(auto data : ump){
            answer += abs(data.second);
        }
        
        return answer;
    }
};