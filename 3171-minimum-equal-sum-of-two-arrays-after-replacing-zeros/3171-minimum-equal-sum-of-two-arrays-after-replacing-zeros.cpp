class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long zeroFirst, sumFirst, zeroSecond, sumSecond;

        zeroFirst = sumFirst = zeroSecond = sumSecond = 0;

        for (auto num : nums1) {
            sumFirst += num;
            if (num == 0) {
                zeroFirst++;
                sumFirst++;
            }
        }

        for (auto num : nums2) {
            sumSecond += num;
           if (num == 0) {
                zeroSecond++;
                sumSecond++;
           }
        }

        if (!zeroFirst && sumSecond > sumFirst || !zeroSecond && sumFirst > sumSecond) {
            return -1;
        }

        return max(sumFirst, sumSecond);
    }
};