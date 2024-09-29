class Trie {
private:
    struct TrieNode{

        TrieNode* word[27];
        bool end;
        int startTotal, endTotal;

        TrieNode(){
            startTotal = endTotal = 0;
            end = false;
            for(int i = 0; i < 27; i++){
                word[i] = nullptr;
            }
        }
    };

public:

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string input) {
        TrieNode* current = root;

        bool valid = false;
        for(auto data : input){
            int index = data - 'a';

            if(current -> word[index] == nullptr){
                current -> word[index] = new TrieNode();
                current -> word[index] -> end = true;
            }

            current = current -> word[index];
            current -> startTotal += 1;
        }

        current -> endTotal += 1;
    }
    
    int countWordsEqualTo(string input) {
        
        TrieNode* current = root;

        for(auto data : input){
            int index = data - 'a';
            if(current -> word[index] == nullptr) return 0;
            current = current -> word[index];
        }

        return current -> endTotal;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* current = root;
        for(auto data : prefix){
            int index = data - 'a';
            if(current -> word[index] == nullptr) return 0;
            current = current -> word[index];
        }

        return current -> startTotal;        
    }
    
    void erase(string input) {
        TrieNode* current = root;

        for(auto data : input){
            int index = data - 'a';
            current = current -> word[index];
            current -> startTotal -= 1;
        }

        current -> endTotal -= 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */