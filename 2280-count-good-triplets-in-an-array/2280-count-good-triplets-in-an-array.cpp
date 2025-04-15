#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define ordered_set with order statistics capabilities
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        unordered_map<int, int> indexMap;

        // Map each value in nums1 to its index
        for (int i = 0; i < n; ++i) {
            indexMap[nums1[i]] = i;
        }

        ordered_set seenIndices;
        long long totalTriplets = 0;

        for (int i = 0; i < n; ++i) {
            int currentIndex = indexMap[nums2[i]];

            // Count elements smaller than currentIndex already seen
            int smaller = seenIndices.order_of_key(currentIndex);

            // Count elements greater than currentIndex still remaining
            int larger = (n - 1 - currentIndex) - (seenIndices.size() - smaller);

            // Calculate number of good triplets where currentIndex is the middle element
            totalTriplets += static_cast<long long>(smaller) * larger;

            // Insert current index to the ordered set
            seenIndices.insert(currentIndex);
        }

        return totalTriplets;
    }
};
