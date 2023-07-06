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

class Solution {
public:
    
    void dfs(Node *root, vector<int>& answer){
        
        for(auto x : root->children){
            answer.push_back(x->val);
            dfs(x, answer);
        }
    }
    
    vector<int> preorder(Node* root) {
        
        if(!root) return {};
        
        vector<int> answer;
        answer.push_back(root->val);
        dfs(root, answer);
        
        return answer;
    }
};