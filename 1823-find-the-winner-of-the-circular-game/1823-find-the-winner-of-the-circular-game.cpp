class Solution {
public:
    
    int recursive(int n, int k){
        
        if(n == 1) return 0;
        return (recursive(n - 1, k) + k) % n;
    }
    
    int findTheWinner(int n, int k) {
        
        int answer = recursive(n , k);
        return answer + 1;
    }
};