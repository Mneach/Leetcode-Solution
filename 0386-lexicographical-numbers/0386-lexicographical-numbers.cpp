class Solution {

private:
    struct TrieNode{
        TrieNode *child[10];
        bool end;

        TrieNode(){
            end = false;
            for(int i = 0; i < 10; i++){
                child[i] = nullptr;
            }
        }
    };

    void construct(TrieNode* root, string number){

        TrieNode* current = root;

        for(auto n : number){
            int num = n - '0';
            if(current -> child[num] == nullptr){
                current -> child[num] = new TrieNode();   
            }

            current -> end = false;
            current = current -> child[num];
        }

        current -> end = true;
    }

    void traverse(TrieNode* root, vector<int> &answer, int currentNumber){

        if(root -> end == true) {
            return;
        }

        for(int i = 0; i < 10; i++){
            if(root -> child[i] != nullptr){
                int next = (currentNumber * 10) + i;
                answer.push_back(next);

                traverse(root -> child[i], answer, next);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        TrieNode* root = new TrieNode();

        for(int i = 1; i <= n; i++){
            
            string number = to_string(i);
            construct(root, number);
        }

        for(int i = 1; i <= min(n, 9); i++){
            answer.push_back(i);
            traverse(root -> child[i], answer, i);
        }

        return answer;
    }
};

/*

Solution Explanation : 
The idea is we will try to use trie to solve the problem, why ? 
-> because it is easier to create sorted number in lexicographical order

Example -> 
we have 1 , 100, 101, 11 , 12 , 2

Trie result
1 - 0
    - 0
    - 1
  - 1
  - 2
2

to construct the answer we can try  traverse the trie with this order
paret -> left child -> right child

Time complexity : O(n log n)
- construct trie -> O(n log n)
- traverse the trie -> O(n)
Memory complexity : O(1) -> constanst based on the value of n
*/