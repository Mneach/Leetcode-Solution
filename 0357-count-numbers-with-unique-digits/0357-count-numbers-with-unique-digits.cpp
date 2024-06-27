class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n == 0) return 1;
        
        if(n == 1) return 10;

        vector<int> bucket(n + 1, 1);
        vector<int> multip(n + 1, 1);
        bucket[0] = 1;
        bucket[1] = 10;

        multip[1] = 9;
        
        int temp = 9;
        for(int i = 2; i <= n; i++){
            bucket[i] = bucket[i - 1] + (multip[i - 1] * temp);
            multip[i] = (multip[i - 1] * temp);
            temp--;
        }

        return bucket[n];
    }
};