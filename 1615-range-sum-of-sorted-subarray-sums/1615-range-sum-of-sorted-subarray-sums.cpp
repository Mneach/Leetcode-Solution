class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefixSum;
        int mod = 1e9 + 7;

        prefixSum.push_back(0);

        for(int i = 0; i < nums.size(); i++){
            
            prefixSum.push_back(nums[i]);
            for(int j = i + 1; j < nums.size(); j++){
                int res = (nums[j] + prefixSum.back()) % mod;
                prefixSum.push_back(res);
            }
        }

        sort(prefixSum.begin(), prefixSum.end());

        for(auto data : prefixSum){
            cout << data << " ";
        }
        cout << endl;

        int answer = 0;

        for(int i = left; i <= right; i++){
            answer = (answer + prefixSum[i]) % mod;
        }

        return answer;
    }
};