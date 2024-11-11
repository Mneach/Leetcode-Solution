class Solution {
public:

    void SieveOfEratosthenes(vector<bool> &prime, int n){

        prime[0] = prime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        vector<bool> prime(1e3 + 1, true);

        SieveOfEratosthenes(prime, 1e3 + 1);

        for(int i = 0; i < nums.size(); i++){
            int prev = i == 0 ? INT_MIN : nums[i - 1];
            int number = nums[i];

            int tempRes = number;
            for(int i = number - 1; i >= 0; i--){
                if(prime[i] == true && number - i > prev){
                    tempRes = number - i;
                    break;
                }
            }

            nums[i] = tempRes;
        }

        // for(int i = 0; i < nums.size(); i++){
        //     cout << nums[i] << " ";
        // }

        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] >= nums[i + 1]) return false;
        }

        return true;
    }
};