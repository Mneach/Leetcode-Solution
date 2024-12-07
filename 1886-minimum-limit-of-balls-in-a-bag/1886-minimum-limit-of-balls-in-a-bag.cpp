class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int left = 1;
        int right = 0;
        int answer = INT_MAX;

        for (auto num : nums) {
            right = max(num, right);
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int res = 0;
            
            for (auto num : nums) {
                if (num < mid) continue;
                res += ceil((double)(num - mid) / mid);
            }

            if (res > maxOperations) {
                left = mid + 1;
            } else {
                right = mid - 1;
                answer = min(answer, mid);
            }
        }

        return answer;
    }
};