class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();

        // Store queries grouped by the maximum index involved.
        vector<vector<pair<int, int>>> groupedQueries(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        vector<int> result(q, -1);

        // Preprocess queries and assign initial results for simple cases.
        for (int i = 0; i < q; ++i) {
            int a = queries[i][0], b = queries[i][1];

            if (a < b && heights[a] < heights[b]) {
                result[i] = b;
            } else if (a > b && heights[a] > heights[b]) {
                result[i] = a;
            } else if (a == b) {
                result[i] = a;
            } else {
                groupedQueries[max(a, b)].emplace_back(max(heights[a], heights[b]), i);
            }
        }

        // Process heights and resolve remaining queries.
        for (int i = 0; i < n; ++i) {
            // Answer queries whose height condition is met at index `i`.
            while (!minHeap.empty() && minHeap.top().first < heights[i]) {
                int queryIndex = minHeap.top().second;
                result[queryIndex] = i;
                minHeap.pop();
            }

            // Add grouped queries for the current index to the heap.
            for (const auto& [heightThreshold, queryIndex] : groupedQueries[i]) {
                minHeap.emplace(heightThreshold, queryIndex);
            }
        }

        return result;
    }
};
