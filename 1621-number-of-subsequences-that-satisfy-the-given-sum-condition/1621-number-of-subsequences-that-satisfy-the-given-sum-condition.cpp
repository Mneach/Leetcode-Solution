class Solution {
public:

    int mod = 1e9 + 7;

    int binarySearch(vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] <= target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return left;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long long int answer = 0;

        vector<int> power(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            power[i] = ((power[i - 1] % mod) * 2) % mod;
        }

        for(int i = 0; i < nums.size(); i++){
            
            int right = binarySearch(nums, target - nums[i]) - 1;
            if(right >= i){
                answer += power[right - i];
                answer %= mod;
            }
        }

        return answer;
    }
};