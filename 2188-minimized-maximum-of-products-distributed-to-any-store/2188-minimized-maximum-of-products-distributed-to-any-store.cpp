class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int minimumX = 1;
        int maximumX = *max_element(quantities.begin(), quantities.end());
        int result = -1;

        while (minimumX <= maximumX) {
            int x = minimumX + (maximumX - minimumX) / 2;

            // check x is a valid answer
            int totalStore = 0;
            int index = 0;

            while (index < quantities.size() && totalStore <= n) {
                int quantity = quantities[index]; 
                if (quantity % x == 0) {
                    totalStore +=  quantity / x;
                } else {
                    totalStore += (quantity / x) + 1;
                }

                index++;
            }

            if (totalStore <= n) {
                result = x;
                maximumX = x - 1;
            } else {
                minimumX = x + 1;
            }
        }

        return result;
    }
};