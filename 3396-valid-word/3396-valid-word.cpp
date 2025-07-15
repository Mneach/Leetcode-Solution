class Solution {
public:
    bool isValid(string word) {
        int totalLength = word.length();
        
        string vowels = "aeiouAEIOU";
        bool checkConsonant = false;
        bool checkVowel = false;
        
        if(totalLength < 3){
            return false;
        }
        
        for(int i = 0; i < word.size(); i++){
            char x = word[i];
            
            if(vowels.find(x) == string::npos && !(x >= 'a' && x <= 'z') && !(x >='A' && x <= 'Z') && !(x >= '0' && x <='9')){
                return false;
            }else if(vowels.find(x) != string::npos){
                checkVowel = true;
            }else if((x >= 'a' && x <= 'z') || (x >='A' && x <= 'Z')){
                checkConsonant = true;
            }
        }
        
        if(checkConsonant && checkVowel){
            return true;
        }
        
        return false;
    }
};