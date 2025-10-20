class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> results(queries.size(), 0);
        vector<int> maximumBeauties(items.size(), 0);

        // sort items array by price asc
        sort(items.begin(), items.end(), [](vector<int> firstItem, vector<int> secondItem) {
            int firstPrice = firstItem[0];
            int secondPrice = secondItem[0];

            return firstPrice < secondPrice;
        });

        for (int i = 0; i < items.size(); i++) {
            int beauty = items[i][1];
            if (i == 0) {
                maximumBeauties[i] = beauty;
            } else {
                int maximumBeauty = max(maximumBeauties[i - 1], beauty);
                maximumBeauties[i] = maximumBeauty;
            }
        }

        for (int i = 0; i < queries.size(); i++) {
            int query = queries[i];
            int maximumItemIndex = -1;
            int left = 0;
            int right = items.size() - 1;

            while (left <= right) {
                int mid = left + (right - left) / 2;;
                int price = items[mid][0];

                if (price <= query) {
                    maximumItemIndex = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (maximumItemIndex == -1) {
                results[i] = 0;
            } else {
                results[i] = maximumBeauties[maximumItemIndex];
            }
        }

        return results;
    }
};