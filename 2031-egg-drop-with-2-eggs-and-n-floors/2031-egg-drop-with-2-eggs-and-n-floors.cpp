class Solution {
public:
    int twoEggDrop(int n) {
        
        int count = 1;

        while(n - count > 0){
            n -= count;
            count++;
        }

        return count;
    }
};