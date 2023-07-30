class Solution {
public:
    string reversePrefix(string word, char ch) {
        
        bool found = false;
        for(int i = 0; i < word.size(); i++){
            
            if(word[i] == ch){
                found = true;
            }
            
            if(found){
                int left = 0;
                int right = i;
                
                while(left < right){
                    swap(word[left], word[right]);
                    left++;
                    right--;
                }
                break;
            }
        }
        
        return word;
    }
};