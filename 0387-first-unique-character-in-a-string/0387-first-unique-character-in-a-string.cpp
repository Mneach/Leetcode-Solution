class Solution {
public:
    int firstUniqChar(string s) {
        
        int answer = -1;
        for(int i = 0; i < s.length(); i++){
            
            int totalSame = 0;
            for(int j = 0; j < s.length(); j++){
                if(i == j) continue;
                if(s[i] == s[j]){
                    totalSame++;
                    break;
                }
            }
            
            if(totalSame == 0){
                answer = i;
                break;
            }
        }
        
        return answer;
    }
};