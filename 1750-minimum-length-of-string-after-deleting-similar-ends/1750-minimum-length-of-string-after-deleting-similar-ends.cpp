class Solution {
public:
    int minimumLength(string s) {
        int size = s.length();
        int left = 0;
        int right = size - 1;
        
        while(true){
            
            if(s[left] != s[right]) {
                break;
            }
            else{
                // move left
                while(left + 1 < size && left <= right && s[left] == s[left + 1]) left++;
                
                // move right
                while(right - 1 >= 0 && left <= right && s[right] == s[right - 1]) right--;
            }
            
            cout << left << " " << right << endl;
            
            if(left >= right){
                break;
            }
            
            left++;
            right--;
        }
        
        cout << left << " " << right << endl;
        
        return (right - left) + 1;
    }
};