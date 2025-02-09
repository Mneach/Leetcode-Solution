
/*

Intuition : 
Bad pair formula -> j - i != nums[j] - nums[i] -> nums[i] - i != nums[j] - j
Good pair formula -> j - 1 == nums[j] - nums[i] -> nums[i] - i == nums[j] - j

It's is eaiser to find good pair, just need to count and put into the hash bap

for the answer, we can use this formula
answer = TotalPair - GoodPair

*/

class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> bucket;
        long long int totalPair = 0;
        long long int goodPair = 0;

        for (int i = 0; i < nums.size(); i++) {
            totalPair += i;
            goodPair += bucket[nums[i] - i];
            bucket[nums[i] - i]++;
        }

        return totalPair - goodPair;
    }
};