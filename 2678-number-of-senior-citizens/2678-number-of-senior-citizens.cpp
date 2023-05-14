class Solution {
public:
    int countSeniors(vector<string>& details) {
        int length = details.size();
        
        int answer = 0;
        for(int i = 0; i < length; i++){
            if(details[i][11] == '6' && details[i][12] > '0'){
                answer++;
            }else if(details[i][11] > '6'){
                answer++;
            }
        }
        return answer;
    }
};