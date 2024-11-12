class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // Sort items by price
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) 
            { 
                return a[0] < b[0]; 
            }
        );

        // Update each item's beauty to be the maximum beauty up to that item's price
        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); ++i) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        // Process each query
        vector<int> results(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            results[i] = findMaxBeauty(items, queries[i]);
        }

        return results;
    }

private:
    int findMaxBeauty(const vector<vector<int>>& items, int targetPrice) {
        int left = 0, right = items.size() - 1;
        int maxBeauty = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int compare = items[mid][0];
            int save = items[mid][1];

            if (compare <= targetPrice) {
                maxBeauty = max(maxBeauty, save);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return maxBeauty;
    }
};
