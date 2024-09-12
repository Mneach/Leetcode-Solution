class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        int answer = 0;
        unordered_map<char,int> ump;

        for(auto c : allowed){
            ump[c]++;
        }

        for(auto data : words){
            bool valid = true;

            for(auto c : data){
                if(ump[c] <= 0){
                    valid = false;
                    break;
                }
            }

            if(valid){
                answer++;
            }
        }

        return answer;
    }
};