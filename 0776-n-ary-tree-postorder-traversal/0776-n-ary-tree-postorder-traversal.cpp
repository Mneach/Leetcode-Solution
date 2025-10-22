/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*

# Observation
1.	We need to run post order traversal in N-ary tree 
   - we need to visit all of the children from the current node, start from the index 0 to children.size() - 2. (visit from left children to the right children), then parent
   - use recursive function to do the traversal


# DFS (pre order traversal)
1.	initialize variables
 - vector<int> results
2.	create a dfs function (void)
   - if root == NULL, return 
   - visit the children
   - push the current node value to the result
3. return the result

Time Complexity : O(N)
N -> total node in a tree

Memory Complexity : O(H)
H -> height of the tree

*/

class Solution {
private:
    vector<int> results;

    void dfs(Node* root) {
        if (root == NULL) {
            return;
        }

        // visit all of the children
        for (int i = 0; i < root -> children.size(); i++) {
            dfs(root -> children[i]);
        }

        // push the current node value to the results
        results.push_back(root -> val);
        return;
    }
public:
    vector<int> postorder(Node* root) {
        dfs(root);
        return results;
    }
};