class Solution {
public:
    long long minCost(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> frequency_diff;

        // Calculate frequency difference between the two arrays
        for (int num : nums1)
            frequency_diff[num]++;
        for (int num : nums2)
            frequency_diff[num]--;

        vector<long long> swap_elements;
        long long min_cost = 0;
        const long long smallest_element = frequency_diff.begin()->first;

        // Check for impossible cases and collect elements to swap
        for (const auto& [num, count] : frequency_diff) {
            if (count % 2 != 0)
                return -1; // Can't balance odd counts

            int swaps_needed = abs(count) / 2;
            for (int i = 0; i < swaps_needed; ++i) {
                swap_elements.push_back(num);
            }
        }

        // Calculate minimum cost by choosing the optimal swaps
        int half_size = swap_elements.size() / 2;
        for (int i = 0; i < half_size; ++i) {
            min_cost += min(swap_elements[i], 2 * smallest_element);
        }

        return min_cost;
    }
};