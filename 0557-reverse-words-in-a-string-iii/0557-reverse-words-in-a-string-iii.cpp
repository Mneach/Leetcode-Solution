class Solution {
public:
    string reverseWords(string s) {
      
        int size = s.length();
        
        int left = 0;
        for(int i = 0; i < size; i++){
            if(s[i] == ' ' || i == size - 1){
                int right;
                
                if(i == size - 1) right = i;
                else right = i - 1;
                
                while(left < right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                } 
                
                left = i + 1;
            }
        } 
        
        
        return s;
    }
};