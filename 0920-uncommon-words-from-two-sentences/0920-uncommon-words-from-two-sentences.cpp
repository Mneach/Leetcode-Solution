class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string,int> ump;

        string temp = "";
        for(int i = 0; i < s1.length(); i++){
            if(s1[i] == ' '){
                ump[temp]++;
                temp = "";
            }else{
                temp += s1[i];
            }
        }

        ump[temp]++;

        temp = "";
        for(int i = 0; i < s2.length(); i++){
            if(s2[i] == ' '){
                ump[temp]++;
                temp = "";
            }else{
                temp += s2[i];
            }
        }

        ump[temp]++;
        

        vector<string> answer;
        for(auto data : ump){
            if(data.second == 1) answer.push_back(data.first);
        }

        return answer;
    }
};