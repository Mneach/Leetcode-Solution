class Node {
public:
    vector<Node*> nextNode;
    bool valid;

    Node(bool valid = false) {
        this->valid = valid;
        nextNode = vector<Node*>(26, nullptr);
    }
};

class WordDictionary {
public:
    Node* root;

    WordDictionary() {
        root = new Node(false);
    }

    void addWord(string word) {
        Node* curr = root;
        for (auto c : word) {
            int index = c - 'a';
            if (curr->nextNode[index] == nullptr) {
                curr->nextNode[index] = new Node(false);
            }
            curr = curr->nextNode[index];
        }
        curr->valid = true;
    }

    bool findWord(int index, string &word, Node* curr) {
        if (curr == NULL) {
            return false;
        }

        if (index == word.size()) {
            return curr -> valid;
        }

        char c = word[index];
        if (c == '.') {
            for (auto next : curr -> nextNode) {
                if (next != NULL && findWord(index + 1, word, next)) {
                    return true;
                }
            }
            return false;
        } else {
            int idx = c - 'a';
            return findWord(index + 1, word, curr->nextNode[idx]);
        }
    }

    bool search(string word) {
        return findWord(0, word, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
