class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        unordered_map<string,int> ump;
        vector<string> answer;

        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){

                int first = i;
                int second = j;
                string temp = to_string(first) + "/" + to_string(second);

                if(ump[temp] > 0) continue;

                answer.push_back(temp);

                int multip = 2;
                while(second * multip <= n){
                    temp = to_string(first * multip) + "/" + to_string(second * multip);
                    multip++;
                    ump[temp]++;                    
                }
            }
        }

        return answer;
    }
};