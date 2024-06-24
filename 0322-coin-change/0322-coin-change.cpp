class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> bucket(amount + 1, -1);
        bucket[0] = 0;

        for(int i = 1; i <= amount; i++){
            int current = i;

            int tempMax = -1;
            for(auto coin : coins){
                if(current - coin >= 0 && bucket[current - coin] >= 0){
                    if(tempMax == -1) tempMax = bucket[current - coin] + 1;
                    else tempMax = min(tempMax, bucket[current - coin] + 1);
                }
            }

            bucket[current] = tempMax;
        }

        // for(auto data : bucket) cout << data << " ";

        return bucket[amount];
    }
};