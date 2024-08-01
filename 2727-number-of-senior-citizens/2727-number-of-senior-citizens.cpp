class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        int answer = 0;

        for(int i = 0; i < details.size(); i++){

            string data = details[i];

            int age = (data[11] - '0') * 10 + (data[12] - '0');

            if(age > 60){
                answer++;
            }
        }

        return answer;
    }
};