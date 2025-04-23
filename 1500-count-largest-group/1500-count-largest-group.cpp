class Solution {
public:
    int countLargestGroup(int n) {
        vector<int> group(100, 0);

        for (int i = 1; i <= n; i++) {
            int number = i;
            int sum = 0;

            while(number > 0) {
                sum += number % 10;
                number /= 10;
            }
            group[sum]++;
        }

        vector<int> result (10001, 0);
        int largest = -1;
        for (int i = 0; i < group.size(); i++) {
            if (group[i] == 0) continue;
            result[group[i]]++;

            largest = max(largest, group[i]);
        }

        return result[largest];
    }
};