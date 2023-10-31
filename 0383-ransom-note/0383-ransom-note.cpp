class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        
        vector<int> arrRansomNote(26, 0);
        vector<int> arrMagazine(26, 0);
        
        for(int i = 0; i < ransomNote.length(); i++){
            arrRansomNote[ransomNote[i] - 'a']++;
        }
        
        for(int i = 0; i < magazine.length(); i++){
            arrMagazine[magazine[i] - 'a']++;
        }
        
        bool valid = true;
        for(int i = 0; i < 26; i++){
            if(arrRansomNote[i] > arrMagazine[i]){
                valid = false;
            }
        }
        
        return valid;
    }
};