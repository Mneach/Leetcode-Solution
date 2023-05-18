class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string answer;
        
        
        int totalLength = word1.length() + word2.length();
        
        int currentIndex = 0;
        int wordIndex1 = 0;
        int wordIndex2 = 0;
        
        while(currentIndex < totalLength){
            if(currentIndex >= word1.length() * 2){
                answer.push_back(word2[wordIndex2]);
                wordIndex2++;
            }else if(currentIndex >= word2.length() * 2){
                answer.push_back(word1[wordIndex1]);
                wordIndex1++;
            }else{
                if(currentIndex % 2 == 0){
                    answer.push_back(word1[wordIndex1]);
                    wordIndex1++;
                }
                else {
                    answer.push_back(word2[wordIndex2]);
                    wordIndex2++;
                }
            }
            
            currentIndex++;
        }
        
        return answer;
    }
};