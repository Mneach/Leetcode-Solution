class Solution {
public:
    
    void recursive(int index, vector<string> &answer, string temp, map<int, string> words, string digits){
        if(index == digits.length()){
            answer.push_back(temp);
        }
        
        string word = words[digits[index] - '0'];
        
        string bucket = temp;
        for(auto data : word){
            temp += data;
            recursive(index + 1, answer, temp , words, digits);
            
            temp = bucket;
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        if(digits.length() == 0) return {};
        vector<string> answer;        
        
        map<int,string> words;
        words[2] = "abc";
        words[3] = "def";
        words[4] = "ghi";
        words[5] = "jkl";
        words[6] = "mno";
        words[7] = "pqrs";
        words[8] = "tuv";
        words[9] = "wxyz";
        
        recursive(0, answer, "", words, digits);
        
        return answer;
    }
};