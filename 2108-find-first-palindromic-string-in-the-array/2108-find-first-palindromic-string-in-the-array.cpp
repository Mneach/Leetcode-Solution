class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        
        string answer = "";
        
        for(int i = 0; i < words.size(); i++){
            
            int left = 0;
            int right = words[i].size() - 1;
            
            bool valid = true;
            while(left <= right){
               if(words[i][left] != words[i][right]) valid = false;
               left++;
               right--;
            }
            
            if(valid){
               answer = words[i];
                break;
            }
        }
        
        return answer;
    }
};