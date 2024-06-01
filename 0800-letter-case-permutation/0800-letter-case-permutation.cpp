class Solution {
public:
    void dfs(string s, vector<string> &answer, int currentIndex, string current) {
        if(currentIndex >= s.length()){
            answer.push_back(current);
            return;
        }

        if(s[currentIndex] >= '0' && s[currentIndex] <= '9'){
            dfs(s, answer, currentIndex + 1, current + s[currentIndex]);
        }else if(s[currentIndex] >= 'a' && s[currentIndex] <= 'z'){
            dfs(s, answer, currentIndex + 1, current + s[currentIndex]);
            dfs(s, answer, currentIndex + 1, current + (char) ((s[currentIndex] - 'a') + 'A'));
        }else{
            dfs(s, answer, currentIndex + 1, current + s[currentIndex]);
            dfs(s, answer, currentIndex + 1, current + (char) ((s[currentIndex] - 'A') + 'a'));
        }
    }

    vector<string> letterCasePermutation(string s) { 
        vector<string> answer; 

        dfs(s, answer, 0, "");

        return answer;    
    }
};