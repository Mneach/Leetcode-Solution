class Solution {
private:
    int answer = 0;
public:

    bool dfs(int i, int number, int currentTake) {
        if (number <= 0) return false;
        int take = 0;
        int multiply = 0;

        while (number > 0) {
            take += number % 10 * pow(10, multiply);
            number /= 10;
            multiply++;
            if(dfs(i, number, currentTake + take)) {
                return true;
            }
        }

        int result = currentTake + take;
        if (result == i) {
            answer += (i * i);
            return true;
        } else {
            return false;
        }
    }

    int punishmentNumber(int n) {
        for (int i = 1; i <= n; i++) {
            dfs(i, i * i, 0);
        }

        return answer;
    }
};
