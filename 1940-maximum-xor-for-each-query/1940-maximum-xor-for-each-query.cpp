class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        vector<int> bucket(nums.size());

        bucket[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            bucket[i] = bucket[i - 1] ^ nums[i];
        }

        vector<int> answer(nums.size());

        int mask = (1 << maximumBit) - 1;

        for(int i = 0; i < nums.size(); i++){
            answer[i] = bucket[nums.size() - 1 - i] ^ mask;
        }

        return answer;
    }
};

/*

# Intuition

x xor y = z
z xor x = y
z xor y = x

so to get the maximum number we can use this formula
x xor y = z
nums[i] xor y = max(2^k, )

# Step to solve

# Time Complexity

# Memory Complexity

*/