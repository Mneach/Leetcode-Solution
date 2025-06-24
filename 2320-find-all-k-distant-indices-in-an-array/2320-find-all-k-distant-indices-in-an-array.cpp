class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> answer;
        int keyLeft = -1;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            if (nums[right] == key) {
                while (left <= right) {
                    if (keyLeft != -1) {
                        if (abs(keyLeft - left) <= k || abs(left - right) <= k) {
                            answer.push_back(left);
                        }
                    } else {
                        if (abs(left - right) <= k) {
                            answer.push_back(left);
                        }
                    }
                    left++;
                }
                keyLeft = right;
            }
        }

        while (left < nums.size()) {
            if (abs(keyLeft - left) <= k) {
                answer.push_back(left);
            }
            left++;
        }

        return answer;
    }
};