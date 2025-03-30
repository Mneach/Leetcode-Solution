class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,vector<int>> ump;

        for(int i = 0; i < s.length(); i++){
            ump[s[i]].push_back(i);
        }

        int answer = 0;

        for(auto data : ump){
            if(data.second.size() % 2 == 0){
                answer += 2;
            }else if(data.second.size() % 2 == 1){
                answer += 1;
            }
        }
        return answer;
    }
};