class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long minMinutes = 1;
        long long maxMinutes = *max_element(ranks.begin(), ranks.end()) * 1LL * cars * cars;
        long long result = maxMinutes;

        while (minMinutes <= maxMinutes) {
            long long minutes = minMinutes + (maxMinutes - minMinutes) / 2;

            // check if minutes is a valid answer
            long long totalCarsRepaired = 0;
            for (int i = 0; i < ranks.size(); i++) {
                totalCarsRepaired += sqrt(minutes / ranks[i]);
            }

            if (totalCarsRepaired >= cars) {
                result = minutes; 
                maxMinutes = minutes - 1;
            } else {
                minMinutes = minutes + 1;
            }
        }

        return result;
    }
};