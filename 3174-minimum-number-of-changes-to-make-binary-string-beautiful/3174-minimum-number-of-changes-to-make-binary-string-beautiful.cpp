class Solution {
public:
    int minChanges(string s) {
        
        int current = 0;
        char take = s[0];
        int answer = 0;
        
        for(int i = 0; i < s.length(); i++){
            if(take == '2') take = s[i];

            if(take == s[i]){
                current++;
            }else{
                // cout << i << " " << current << endl;
                if(current % 2 == 1){
                    answer++;
                    current = 0;
                }else{
                    current = 1;
                    take = s[i];
                }
            }
        }

        return answer;
    }
};