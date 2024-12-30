class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int mod = 1e9 + 7;
        vector<int> arr(1e5 + 1, 0);
        arr[0] = 1;

        for (int i = 1; i <= high; i++) {
            int result = 0;
            if (i >= zero) {
                result = result + (arr[i - zero] % mod);
            }
            
            if(i >= one) {
                result += (arr[i - one] % mod);
            }

            arr[i] = result % mod;
        }

        int answer = 0;
        for (int i = low; i <= high; i++) {
            answer = (answer + arr[i]) % mod;
        }

        return answer;
    }
};