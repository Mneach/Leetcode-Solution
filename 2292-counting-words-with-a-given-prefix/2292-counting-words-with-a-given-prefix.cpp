class Node {
public:
    Node *next[26];
    int total;
    bool end;
    
    Node() {
        total = 1;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
        end = false;
    }
};

class Solution {
public:

    void add(Node* root, string word) {

        Node* current = root;
        for (auto c : word) {
            int ascii = c - 'a';

            if (current -> next[ascii] == NULL) {
                current -> next[ascii] = new Node();
            } else {
                current -> next[ascii] -> total = current -> next[ascii] -> total + 1;
            }

            current -> end = false;
            current = current -> next[ascii];
        }

        current -> end = true;
    }  

    int prefixCount(vector<string>& words, string pref) {
        Node* root = new Node();  

        for (auto word : words) {
            add(root, word);
        }      

        for (auto c : pref) {
            int ascii = c - 'a';
            if (root -> next[ascii] == NULL) {
                return 0;
            }
            root = root -> next[ascii];
        }

        return root -> total;
    }
};