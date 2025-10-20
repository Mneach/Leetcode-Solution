
/*

# Observation
⦁	items[i] = [price, beauty]
⦁	For every query we need to determine the maximum beauty of an item whose price <= queries[j], 
   - if the item doesn't exists return 0
   - otherwise return the index of that item

# Brute Force Solution

# Simulation

          J
items = [[1,2],[3,2],[2,4],[5,6],[3,5]]

                     I
queries = [1,2,3,4,5,6]

query[i] = 5
-> [1,2],[3,2],[3,5],[5,6],[2,4]

results = [2,4,5,5,6,6]

# Pseudocode
initialize variables
 - vector<int> results
loop for every query in the queries array
   - result = 0
   - loop for every item in items array
     - if item price < query
       - result = max(result, item beauty)
   - results.push_back(result)
3. return the result

Time Complexity : O(N * M)
N -> size of items
M -> size of the query

Memory Complexity : O(M)
M -> size of the result array = size of the queries array


# Binary Search

original items : [[1,2],[3,2],[2,4],[5,6],[3,5]]

sorted items by price asc = [[1,2],[2,4],[3,2],[3,5],[5,6]]
maximumBeauty = [2,4,4,5,6]

left = 4
right = 3
mid = 4
maximumItemIndex = 3

query[i] = 3

                          L
                          M
                    R
[[1,2],[2,4],[3,2],[3,5],[5,6]] 


to get the maximum beauty -> maximumBeauties[maximumItemIndex] = 5

# Pseudocode 
initialize variables
   - left = 0
   - right = items.size() - 1
   - vector<int> results
2. sort the original items
3. create maximum beauty array
4. for every query in queries
   - maximumItemIndex = -1
   - while left <= right (do binary search algorithm)
     - mid = left + (right - left) / 2
     - price = items[mid][0]
     - if (price <= query)
       - maximumItemIndex = mid
       - move left pointer to mid + 1
     - else
       - move right pointer to mid - 1
   - if maximumItemIndex == -1
     - push 0 into the results array
   - else
     - push maximumBeauties[maximumItemIndex] to the results array
5. return the results array

Time Complexity : O(N log N + N + M * log N)
M -> size of query
N -> size of items

first N log N -> come from sorting algorithm
second N -> because we need to create beauties array
third M * log N -> to get the result for every query

Memory Complexity : O (N + K)
N -> size of items
K -> size of beauties array = size of items

first N -> come from sorting algorithm
K -> because of we need to create beauties array

*/

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