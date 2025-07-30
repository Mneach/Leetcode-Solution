class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int answer = 0;
        int current = 1;

        while (n != 0) {
            if (n % 2 == 0) answer += current;
            n /= 2;
            current *= 2;
        }

        return answer;
    }
};