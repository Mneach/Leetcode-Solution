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
        if(root){
            
            for(auto x : root->children){
                dfs(x, answer);
            }
            
            answer.push_back(root->val);
        }
    }
    
    vector<int> postorder(Node* root) {
        vector<int> answer;
        dfs(root, answer);
        
        return answer;
    }
};



