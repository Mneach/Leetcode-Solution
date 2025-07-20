class Solution {
public:
    int reverseBits(int n) {
        
        if (n == 0) return 0;

        int answer = 0;

        for (int i = 0; i < 32; i++) {
            answer <<= 1;
            if ((n & 1) == 1) answer++;
            n >>= 1;
        }

        return answer;
    }
};