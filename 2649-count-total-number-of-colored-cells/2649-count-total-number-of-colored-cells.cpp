class Solution {
public:
    long long coloredCells(int n) {
        long long answer = 1;
        long long plus = 4;

        for (int i = 2; i <= n; i++) {
            answer = answer + plus;
            plus += 4;
        }

        return answer;
    }
};