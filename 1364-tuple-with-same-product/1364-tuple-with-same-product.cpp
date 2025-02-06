
/*

Intuition : 

We can use some math to solve this problem, we just need to find the pattern

a * b == c * d
(a * b) == (c * d)
pair1 == pair2

we can use count frequency, just put the multiply result inside the hashmap, use prefix sum to compute how many pair that we can construct

total pair = total pair that we can construct
formula = ((x - 1) * 4) * x

(x - 1) -> is because we can only construct (x - 1) total pair
* 4 -> is because we can swap between the position
x -> is because we will have x pair

0 = 0
1 = 0
2 = 8
3 = 24
4 = 48

*/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int answer = 0;
        vector<long long> prefixSum(1001, 0);
        unordered_map<long long,int> ump;

        // precompute
        for (int i = 1; i < prefixSum.size(); i++) {
            prefixSum[i] = ((i - 1) * 4) * i;
        }

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long result = 1LL * nums[i] * nums[j];
                ump[result]++;
            }
        }

        for (auto data : ump) {
            answer += prefixSum[data.second];
        }

        return answer;
    }
};