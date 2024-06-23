class Solution {
public:

    int answer = 0;

    void helper(int n, int currentIndex, int used){
        if(currentIndex > n){
            answer++;
            return;
        }
        
        for(int i = 1; i <= n; i++){
            if((used & (1 << i)) == 0 && gcd(i, currentIndex) == 1){
                helper(n, currentIndex + 1, used | (1 << i));
            }
        }
    }

    int selfDivisiblePermutationCount(int n) {

        helper(n, 1, 0);
        
        return answer;
    }
};