class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        vector<int> arrAllowed(26, 0);
        
        for(int i = 0 ; i < allowed.length(); i++){
            arrAllowed[allowed[i] - 'a']++;
        }
        
        int answer = 0;
        for(int i = 0; i < words.size(); i++){
            
            string word = words[i];
            
            bool valid = true;
            for(int j = 0; j < word.length(); j++){
                if(arrAllowed[word[j] - 'a'] == 0){
                    valid = false;
                }
            }
            
            if(valid) answer++;
        }
        
        return answer;
    }
};