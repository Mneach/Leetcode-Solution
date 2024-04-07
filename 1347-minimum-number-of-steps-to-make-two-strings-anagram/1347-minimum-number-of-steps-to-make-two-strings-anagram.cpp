class Solution {
public:
    int minSteps(string s, string t) {
       
        unordered_map<char,int> umpS;
        unordered_map<char,int> umpT;
        
        for(int i = 0; i < s.length(); i++){
            umpS[s[i]]++;
            umpT[t[i]]++;
        }
        
        int answer = 0;
        for(auto data : umpS){
            if(umpT.count(data.first) > 0){
                if(data.second > umpT[data.first]){
                    answer += data.second - umpT[data.first];    
                }
            }else{
                answer += data.second;
            }
        }
        
        return answer;
    }
};