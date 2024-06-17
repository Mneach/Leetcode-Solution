class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<long long int,long long int> bucket;
        long long int maximum = INT_MAX;
        
        long long int current = 0;
        while(current * current <= maximum){
            bucket[current * current]++;
            current++;
        }

        for(long long int i = 0; i <= 100000; i++){
            if(i > c) return false;

            long long int reminder = c - (i * i);

            if(reminder < 0) return false;

            if(bucket[reminder] > 0) return true;
        }

        return false;
    }
};