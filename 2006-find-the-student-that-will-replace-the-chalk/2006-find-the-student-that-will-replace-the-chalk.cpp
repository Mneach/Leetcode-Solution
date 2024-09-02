class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        
        vector<long long int> prefixSum(chalk.size(), 0);
        int answer = 0;

        for(int i = 0; i < chalk.size(); i++){
            if(i == 0){
                prefixSum[i] = chalk[i];
            }else{
                prefixSum[i] = chalk[i] + prefixSum[i - 1];
            }
        }

        int index = upper_bound(prefixSum.begin(), prefixSum.end(), k) - prefixSum.begin();
        if(index == prefixSum.size()) index -= 1;

        long long int divider = prefixSum[index];
        long long int reminder = k % divider;

        if(reminder == 0){
            return (index + 1) % prefixSum.size();
        }else{
            index = upper_bound(prefixSum.begin(), prefixSum.end(), reminder) - prefixSum.begin();
            return index;
        }
    }
};