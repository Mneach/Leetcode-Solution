class Solution {
public:
    int maxLength(vector<int>& nums) {
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {

            long long int prod = -1;
            long long int gcdX = 0;
            long long int lcmY = 0;
            int temp = 1;
            for (int j = i; j < nums.size(); j++) {

                if (prod == -1) {
                    gcdX = nums[j];
                    lcmY = nums[j];
                    prod = nums[j];
                    continue;
                } else {
                    gcdX = gcd(gcdX, nums[j]);
                    lcmY = lcm(lcmY, nums[j]);
                    prod *= nums[j];
                }

                if (prod == gcdX * lcmY) {
                    temp++;
                } else {
                    break;
                }
            }

            answer = max(answer, temp);
        }

        return answer;
    }
};