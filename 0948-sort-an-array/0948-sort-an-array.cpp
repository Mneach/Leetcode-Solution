class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> bucket;
        int minimum = INT_MAX;
        int maximum = INT_MIN;

        for (auto num : nums) {
            minimum = min(num, minimum);
            maximum = max(num, maximum);
            bucket[num]++;
        }

        int index = 0;
        vector<int> answer;
        for (int i = minimum; i <= maximum; i++) {
            while (bucket[i] > 0) {
                answer.push_back(i);
                bucket[i] -= 1;
            }
        }
        
        return answer;
    }
};