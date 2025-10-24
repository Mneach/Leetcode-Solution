/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*

# Observation
1.	given nums where elements sorted in asc order
2.	Build high-balance binary search tree
3. binary search tree rules
   - parent value < right child
   - parent value > left child


# Simulation
   
          0   1  2 3 4 5  6
nums = [-20,-10,-3,0,5,9,15]

         0
        / \
       -3  5
       /    \
     -10     9
      /       \
     -20       15


          0
       /     \
     -10      9     
     / \      / \
   -20  -3   5  15

# Pseudocode
1.	create construct functions (vector<int> &nums, leftIndex, rightIndex)
   - if (leftIndex > rightIndex)
     - return NULL
   - index = leftIndex + (rightIndex - leftIndex) / 2
   - currentNode = create node with nums[index] as a value of that node
   - visit left node
     - Node newNode = dfs(nums, leftIndex, index - 1)
     - if newNode != NULL, then add newNode as left child of current node
   - visit right node
     - Node newNode = dfs(nums, index + 1, rightIndex)
     - if newNode != NULL, then add newNode as right child of current node
   - return current node
2. call construct function
   - Node root = construct(nums, 0, nums.size() - 1)
3. return the root

Time Complexity : O(N)
N -> size of nums

Memory Complexity : (log N)
N -> size of nums

*/

class Solution {
    TreeNode* construct(vector<int> &nums, int leftIndex, int rightIndex) {
        if (leftIndex > rightIndex) {
            return NULL;
        }

        int index = leftIndex + (rightIndex - leftIndex) / 2;
        TreeNode* currentNode = new TreeNode(nums[index]);

        TreeNode* leftChild = construct(nums, leftIndex, index - 1);
        TreeNode* rightChild = construct(nums, index + 1, rightIndex);

        if (leftChild != NULL) {
            currentNode -> left = leftChild;
        }

        if (rightChild != NULL) {
            currentNode -> right = rightChild;
        }

        return currentNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = construct(nums, 0, nums.size() - 1);

        return root;
    }
};