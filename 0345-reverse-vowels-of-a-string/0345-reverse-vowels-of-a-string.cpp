class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        string data = "aAeEiIoOuU";
        for(int i = 0; i < s.length(); i++){
            if(data.find(s[i]) != string::npos) vowels += s[i];
        }
        
        int index = 0;
        for(int i = s.length() - 1; i >= 0; i--){
            if(data.find(s[i]) != string::npos){
                s[i] = vowels[index];
                index++;
            }
        }
        
        return s;
    }
};