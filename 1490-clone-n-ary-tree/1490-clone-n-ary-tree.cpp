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
    Node* cloneTree(Node* root) {
       
        if(!root) return root;
        
        Node* newRoot = NULL;
        
        queue<pair<Node*, Node*>> q;
        
        q.push({newRoot, root});
        
        while(q.empty() == false){
            
            Node *newNode = q.front().first;
            Node *oldNode = q.front().second;
            Node *insertedNode = new Node(oldNode->val);
            
            q.pop();
            
            if(newRoot == NULL){
                newRoot = insertedNode;
            }else{
                newNode->children.push_back(insertedNode);
            }
            
            for(auto child : oldNode->children){
                q.push({insertedNode, child});
            }
        }
        
        return newRoot;
    }
};

