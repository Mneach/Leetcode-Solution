class Solution {
public:

    bool check(int number) {

        while (number > 0) {
            if (number % 10 == 0) return false;
            
            number /= 10;
        }

        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int first = 1;  
        n -= 1;
        while (n > 0) {

            if (check(first) && check(n)) {
                return {first, n};
            }

            first++;
            n--;
        }

        return {-1, -1};
    }
};