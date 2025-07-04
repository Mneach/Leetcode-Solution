class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        
        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                
                int end = i;
                for(int start = 0; start <= (i / 2); start++){
                    swap(word[start], word[end]);
                    end--;
                }
                break;
            }
        }
        
        return word;
    }
};