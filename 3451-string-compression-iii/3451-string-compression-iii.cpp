class Solution {
public:
    string compressedString(string word) {
        
        string comp = "";
        int total = 0;
        for(int i = 0; i < word.size() - 1; i++){
            total++;
            
            if(word[i] != word[i + 1] || total == 9){
                comp += to_string(total) + word[i];
                total = 0;
            }
        }
        
        total += 1;
        comp += to_string(total) + word[word.size() - 1];
        
        return comp;
    }
};