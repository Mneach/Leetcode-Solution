class Solution {
private:

    struct TrieNode{
        TrieNode* next[27];
        bool end;

        TrieNode(){
            end = false;
            for(int i = 0; i < 27; i++){
                next[i] = nullptr;
            }
        }
    };

    void construct(TrieNode* root, string word){

        TrieNode* current = root;

        for(auto c : word){
            
            if(current -> next[c - 'a'] == nullptr){
                current -> next[c - 'a'] = new TrieNode();
            }

            current = current -> next[c - 'a'];
        }

        current -> end = true;
    }

    bool traverse(TrieNode* root, string word){
       
       for(auto c : word){
            root = root -> next[c - 'a'];
            if(root == nullptr || root -> end == false){
                return false;
            }
       }

       return true;
    }

public:
    string longestWord(vector<string>& words) {

        sort(words.begin(), words.end());
        
        TrieNode* root = new TrieNode();

        for(auto word : words){
            construct(root, word);
        }

        string answer = "";

        for(auto word : words){
            bool result = traverse(root, word);

            if(result){
                if(answer.length() == word.length() && word < answer){
                    answer = word;
                }else if(answer.length() < word.length()){
                    answer = word;
                }
            }
        }

        return answer;
    }
};