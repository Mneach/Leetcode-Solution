class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            if (i == 0) {
                prefix.push_back(nums[i]);
            } else {
                prefix.push_back(prefix[i - 1] * nums[i]);
            }
        }

        int index = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (index == 0) {
                suffix.push_back(nums[i]);
            } else {
                suffix.push_back(nums[i] * suffix[index - 1]); 
            }

            index++;
        }

        vector<int> answer;
        for (int i = 0; i < size; i++) {

            if (i == 0) {
               answer.push_back(suffix[size - 2]); 
            } else if (i == size - 1) {
               answer.push_back(prefix[size - 2]); 
            } else {
               answer.push_back(prefix[i - 1] * suffix[size - i - 2]);
            }
        }

        return answer;
    }
};