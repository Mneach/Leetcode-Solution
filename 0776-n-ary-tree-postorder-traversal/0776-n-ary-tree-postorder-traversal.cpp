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

    void preOrder(Node* root, vector<int> &answer){
        if(root){
            int index = 0;
            while(index < root->children.size()){
                preOrder(root -> children[index], answer);
                
                index++;
                if(index >= root->children.size()){
                    break;
                }
                preOrder(root -> children[index], answer);
                index++;
            }
            answer.push_back(root->val);
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> answer;

        preOrder(root, answer);

        return answer;
    }
};