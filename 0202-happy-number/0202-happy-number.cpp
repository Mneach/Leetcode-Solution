class Solution {
public:
    bool isHappy(int n) {
        int temp = n;
        unordered_map<int,int> visited;

        while (n != 1) {
            if (visited.count(n) > 0) {
                return false;
            }
            visited[n]++;
            int temp = n;
            n = 0;
            while (temp > 0) {
                int mod = temp % 10;
                temp /= 10;
                n += (pow(mod, 2));
            }
        }

        return true;
    }
};