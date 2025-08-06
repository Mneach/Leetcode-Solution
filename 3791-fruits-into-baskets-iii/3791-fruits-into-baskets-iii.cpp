class Solution {
private:
    vector<int> segment_tree;

    void buildSegmentTree(vector<int>& baskets, int node, int start, int end) {
        if (start == end) {
            segment_tree[node] = baskets[start];
            return;
        }

        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        buildSegmentTree(baskets, left_child, start, mid);
        buildSegmentTree(baskets, right_child, mid + 1, end);

        segment_tree[node] = max(segment_tree[left_child], segment_tree[right_child]);
    }

    int findAndRemoveBasket(int node, int start, int end, int fruit_size) {
        if (segment_tree[node] < fruit_size) {
            return -1;  // No suitable basket found
        }

        if (start == end) {
            segment_tree[node] = -1;  // Mark basket as used
            return start;
        }

        int mid = start + (end - start) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        int basket_index;
        if (segment_tree[left_child] >= fruit_size) {
            basket_index = findAndRemoveBasket(left_child, start, mid, fruit_size);
        } else {
            basket_index = findAndRemoveBasket(right_child, mid + 1, end, fruit_size);
        }

        // Update the segment tree after modification
        segment_tree[node] = max(segment_tree[left_child], segment_tree[right_child]);

        return basket_index;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        int unplaced_count = 0;

        segment_tree.resize(4 * n);  // Sufficient size for segment tree
        buildSegmentTree(baskets, 0, 0, n - 1);

        for (int fruit : fruits) {
            if (findAndRemoveBasket(0, 0, n - 1, fruit) == -1) {
                unplaced_count++;
            }
        }

        return unplaced_count;
    }
};