class Solution {
public:
    string makeFancyString(string s) {
        
        int total = 0;
        int left = 0;
        string answer = "";

        for(int i = 0; i < s.length(); i++){
            if(s[i] == s[left]){
                total++;   
            }else{
                if(total >= 3){
                    answer += s[left];
                    answer += s[left];
                }else{
                    while(left < i){
                        answer += s[left];
                        left++;
                    }
                }
                total = 1;
                left = i;
            }
        }

        if(total >= 3){
            answer += s[left];
            answer += s[left];
        }else{
            while(left < s.length()){
                answer += s[left];
                left++;
            }
        }

        return answer;
    }
};