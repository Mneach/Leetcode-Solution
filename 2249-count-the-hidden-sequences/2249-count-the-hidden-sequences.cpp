class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0;
        int y = 0;
        int current = 0;
        bool mark = true;

        for (int d : differences) {
            current += d;
            x = min(x , current);
            y = max(y, current);

            if (y - x > upper - lower) {
                mark = false;
                break;
            }
        }

        if (mark) {
            return (upper - lower) - (y - x) + 1;
        } else {
            return 0;
        }
    }
};