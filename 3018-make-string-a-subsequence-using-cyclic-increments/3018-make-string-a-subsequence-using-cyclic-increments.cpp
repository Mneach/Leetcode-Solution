class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int indexStr2 = 0;
        
        for(int i = 0; i < str1.size(); i++){
            int currentChar = str1[i];
            int nextChar;
            if(str1[i] == 'z') nextChar = 'a';
            else nextChar = str1[i] + 1;
            
            if(currentChar == str2[indexStr2] || nextChar == str2[indexStr2]){
                indexStr2++;
            }
            
            if(indexStr2 == str2.size()) break;
        }
        
        return indexStr2 == str2.size();
    }
};