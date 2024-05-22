class Solution {
public:
    
    bool checkPalindrome(string s, int start, int end){
        
        while(start < end){
            
            if(s[start] != s[end]){
                return false;
            }
            
            start++;
            end--;
        }
        
        return true;
    }
        
    void dfs(vector<vector<string>> &answer, vector<string> &temp, string &s, int currentIndex){
        
        if(currentIndex >= s.length()){
            answer.push_back(temp);
        }
        
        for(int i = currentIndex; i < s.length(); i++){
            if(checkPalindrome(s, currentIndex, i)){
                temp.push_back(s.substr(currentIndex, i - currentIndex + 1));
                dfs(answer, temp, s, i + 1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {

        vector<vector<string>> answer;
        vector<string> temp;
        
        dfs(answer, temp, s, 0);
        return answer;
    }
};