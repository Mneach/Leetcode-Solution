/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*

Observation
⦁	We have perfect binary tree, that means at level i, we can have 2^(i-1) nodes
    - perfect binary tree is a combination between full binary tree and complete binary tree, that means every level will alwasy have 0 or 2 childs
⦁	If there is no next right node, the next pointer should be set to NULL.
⦁	If there is a next right node, connect the current node with the next right node
⦁	maximum node at level i = 2^(i - 1)
  - we can utilize that information to reset the temp node

# Using BFS
1. initialize variables
   - queue<Node*> q
   - level = 1
   - availableNode = pow(2, level);
   - tempNode
2. push root into the queue
3. while queue is not empty
   - get Node from the queue
   - get left child
   - get right child
   - if left child && right child == NULL
     - break
   - if tempNode == NULL
     - tempNode = node -> left child
     - tempNode -> next = rightChild
     - tempNode = tempNode -> next
   - else
     - tempNode -> next = leftChild
     - tempNode = tempNode -> next
     - tempNode -> next = rightChild
     - tempNode = tempNode
   - push left child and right child to the queue
   - availableNode -= 2
   - if (availableNode == 0)
     - level++
     - availableNode = pow(2, level)
     - tempNode = NULL 
4. return the root

Time Complexity : O(N)
N -> total nodes in the tree

Memory Complexity : O (N)
N -> total nodes in the tree
*/

class Solution {
public:
    Node* connect(Node* root) {

        if (root == NULL) {
            return root;
        }

        queue<Node*> q;
        Node* tempNode = NULL;
        int level = 1;
        int availableNode = pow(2, level);

        q.push(root);

        while (q.empty() == false) {
            Node* node = q.front();
            q.pop();

            Node* leftChild = node -> left;
            Node* rightChild = node -> right;

            if (leftChild == NULL && rightChild == NULL) {
                break;
            }

            if (tempNode == NULL) {
                tempNode = leftChild;
                tempNode -> next = rightChild;
                tempNode = tempNode -> next;
            } else {
                tempNode -> next = leftChild;
                tempNode = tempNode -> next;
                tempNode -> next = rightChild;
                tempNode = tempNode -> next;
            }

            q.push(leftChild);
            q.push(rightChild);

            availableNode -= 2;

            if (availableNode == 0) {
                level += 1;
                tempNode = NULL;
                availableNode = pow(2, level);
            }
        }

        return root;
    }
};