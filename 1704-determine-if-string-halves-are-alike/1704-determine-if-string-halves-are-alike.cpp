class Solution {
public:
    
    bool isVowel(char x, string vowel){
        
        if(find(vowel.begin(), vowel.end(), x) != vowel.end()){
            return true;
        }else{
            return false;
        }
    }
    
    bool halvesAreAlike(string s) {
        string vowel = "aeiouAEIOU";
        
        int bucket = 0;
        for(int i = 0; i < s.length(); i++){
            if(isVowel(s[i], vowel)){
                bucket++;
            }
        }
        
        int bucket2 = 0;
        for(int j = s.length() - 1; j >= 0; j--){
            if(isVowel(s[j], vowel)){
                bucket2++;
                bucket--;
            }
            
            if(bucket == bucket2 && j == s.length() / 2){
                return true;
            }
        }
        
        return false;
    }
};