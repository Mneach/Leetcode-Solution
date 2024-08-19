class Solution {
public:

    int maxRes = 1000;

    int recursive(int current, int next, int n){
        if(current == n) return 0;

        if(current > n) return maxRes;

        return min(1 + recursive(current + next, next,n), 2 + recursive(current * 2, current,n));
    }

    int minSteps(int n) {
        if(n == 1) return 0;

        return 1 + recursive(1, 1, n);
    }
};