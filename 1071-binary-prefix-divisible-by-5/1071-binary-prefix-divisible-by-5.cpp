class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> result;
        int current_remainder = 0;
        
        for (const int bit : nums) {
            current_remainder = (current_remainder * 2 + bit) % 5;
            result.push_back(current_remainder == 0);
        }
        
        return result;
    }
};