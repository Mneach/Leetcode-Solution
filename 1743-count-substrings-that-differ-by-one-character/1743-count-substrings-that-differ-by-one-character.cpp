class Solution {
public:
    int countSubstrings(string s, string t) {
        int answer = 0;

        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < t.length(); j++){

                int subS = i;
                int subT = j;
                int diff = 0;

                while(subS < s.length() && subT < t.length()){
                    if(s[subS] != t[subT]) diff++;

                    if(diff == 1) answer++;
                    else if(diff > 1) break;

                    subS++;
                    subT++;
                }
            }
        }

        return answer;
    }
};