class Solution {
public:

    void dfs(vector<string> &answer, string s, string current, int currentIndex){
        if(currentIndex >= s.length()){
            answer.push_back(current);
            return;
        }

        if(s[currentIndex] == '{'){
            string temp = "";

            while(s[currentIndex] != '}'){
                if(s[currentIndex] >= 'a' && s[currentIndex] <= 'z'){
                    temp += s[currentIndex];
                }
                currentIndex++;
            }

            for(int k = 0; k < temp.length(); k++){
                dfs(answer, s, current + temp[k], currentIndex + 1);
            }
        }else if(s[currentIndex] >= 'a' && s[currentIndex] <= 'z'){
            dfs(answer, s, current + s[currentIndex], currentIndex + 1);
        }
    }

    vector<string> expand(string s) {
        vector<string> answer;

        dfs(answer, s , "", 0);

        sort(answer.begin(), answer.end());

        return answer;
    }
};