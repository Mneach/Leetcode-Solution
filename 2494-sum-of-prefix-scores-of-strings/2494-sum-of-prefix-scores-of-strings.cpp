class Solution {
    struct TrieNode{
        
        TrieNode* next[27];
        bool end;
        int total;

        TrieNode(){
            total = 1;
            end = true;
            for(int i = 0; i < 27; i++){
                next[i] = nullptr;
            }
        }
    };

    void constructTree(TrieNode *root, string word){

        for(auto c : word){
            int index = c - 'a';
            if(root -> next[index] == nullptr){
                root -> end = false;

                root -> next[index] = new TrieNode();
                root -> next[index] -> end = true;
            }else{
                root -> next[index] -> total += 1;
            }

            root = root -> next[index];
        }
    }

    int traverseTree(TrieNode *root, string word){
        int result = 0;
        for(auto c : word){
            int index = c - 'a';
            root = root -> next[index];
            result += root -> total;
        }
        
        return result;
    }
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        vector<int> answer;
        TrieNode* root = new TrieNode();

        // construct the tree
        for(auto word : words){
            constructTree(root, word);
        }

        // get the answer
        for(auto word : words){
            int result = traverseTree(root, word);
            answer.push_back(result);
        }

        return answer;
    }
};