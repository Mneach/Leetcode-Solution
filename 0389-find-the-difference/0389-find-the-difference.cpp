class Solution {
public:
    char findTheDifference(string s, string t) {
        
        vector<int> arrS(28, 0);
        vector<int> arrT(28, 0);
        
        for(int i = 0; i < s.length(); i++){
            arrS[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.length(); i++){
            arrT[t[i] - 'a']++;
        }
        
        char answer = 'a';
        
        for(int i = 0; i < 28; i++){
            if(arrS[i] != arrT[i]){
                answer = (i + 'a');
                break;
            }
        }
        
        return answer;
    }
};