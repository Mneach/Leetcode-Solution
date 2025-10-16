class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int minimumCandy = 1;
        int maximumCandy = *max_element(candies.begin(), candies.end());
        int result = 0;

        // do binary search algoritm
        while (minimumCandy <= maximumCandy) {
            int currentCandy = minimumCandy + (maximumCandy - minimumCandy) / 2;

            // check if we can distribute current candy to the k childs
            bool valid = false;
            long long totalChild = 0;
            for (int i = 0; i < candies.size(); i++) {
                totalChild += candies[i] / currentCandy;

                if (totalChild >= k) {
                    valid = true;
                    break;
                }
            }

            if (valid) {
                result = max(result, currentCandy);
                minimumCandy = currentCandy + 1;
            } else {
                maximumCandy = currentCandy - 1;
            }
        }

        return result;
    }
};