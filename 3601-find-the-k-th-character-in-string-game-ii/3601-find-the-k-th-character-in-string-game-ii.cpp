class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int answer = 0;

        while(k != 1) {
            long long jump = log2(k);

            if ((1LL << jump) == k) jump--;

            long long prev = pow(2, jump);
            k = k - prev;

            // that means we shift the current charater to + 1
            // example a to b, b to c, etc.
            if (operations[jump] == 1) {
                answer++;
            }
        }

        // there is a case when answer > 26, but we only have 26 character
        return 'a' + (answer % 26);
    }
};