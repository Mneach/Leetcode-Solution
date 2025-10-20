class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> results;
        vector<int> maximumBeauties;

        // sort items array by price asc
        sort(items.begin(), items.end(), [](vector<int> firstItem, vector<int> secondItem) {
            int firstPrice = firstItem[0];
            int secondPrice = secondItem[0];

            return firstPrice < secondPrice;
        });

        for (int i = 0; i < items.size(); i++) {
            int beauty = items[i][1];
            if (i == 0) {
                maximumBeauties.push_back(beauty);
            } else {
                int maximumBeauty = max(maximumBeauties[i - 1], beauty);
                maximumBeauties.push_back(maximumBeauty);
            }
        }

        for (auto query : queries) {
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
                results.push_back(0);
            } else {
                results.push_back(maximumBeauties[maximumItemIndex]);
            }
        }

        return results;
    }
};