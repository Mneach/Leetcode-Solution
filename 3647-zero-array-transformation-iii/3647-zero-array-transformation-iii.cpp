using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // Sort queries based on start index in ascending order
        sort(queries.begin(), queries.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        priority_queue<int> max_heap; // Stores end indices of active intervals
        vector<int> delta_array(nums.size() + 1, 0); // For range updates
        int current_operations = 0;
        int query_ptr = 0; // Pointer to track processed queries

        for (int i = 0; i < nums.size(); ++i) {
            // Apply the delta from previous operations
            current_operations += delta_array[i];
            
            // Add all queries that start at current index
            while (query_ptr < queries.size() && queries[query_ptr][0] == i) {
                max_heap.push(queries[query_ptr][1]);
                ++query_ptr;
            }
            
            // Perform operations until we meet the requirement or can't anymore
            while (current_operations < nums[i] && !max_heap.empty() && max_heap.top() >= i) {
                ++current_operations;
                // Mark the end of this operation's effect
                delta_array[max_heap.top() + 1] -= 1;
                max_heap.pop();
            }
            
            // If we couldn't meet the requirement, return -1
            if (current_operations < nums[i]) {
                return -1;
            }
        }
        
        // Return the number of unused queries
        return max_heap.size();
    }
};