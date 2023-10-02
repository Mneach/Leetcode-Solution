class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int count = 0;
        
        for(int i = 31; i >= 0; i--){
            
            int first = (x & (1 << i));
            int second = (y & (1 << i));
            
            if(first != second){
                count++;
            }
        }
        
        return count;
    }
};