class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string answer1 = "";
        for(int i = 0 ; i < word1.size(); i++){
            answer1 += word1[i];
        }
        
        string answer2 = "";
        for(int i = 0; i < word2.size(); i++){
            answer2 += word2[i];
        }
        
        return answer1 == answer2;
    }
};