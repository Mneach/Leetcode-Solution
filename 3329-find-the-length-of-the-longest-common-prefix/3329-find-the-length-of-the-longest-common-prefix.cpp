class Solution {
private:
    struct TrieNode{
        TrieNode* numbers[10];
        bool end;

        TrieNode(){
            end = false;
            for(int i = 0; i < 10; i++){
                numbers[i] = nullptr;
            }
        }
    };

    void constructTree(TrieNode* root, string number){

        for(auto data : number){
            if(root -> numbers[data - '0'] == nullptr){
                root -> numbers[data - '0'] = new TrieNode();
                root -> end = false;
            }
            root = root -> numbers[data - '0'];
        }

        root -> end = true;
    }

    int traverse(TrieNode* root, string number){
        int result = 0;
        for(auto data : number){
            if(root -> numbers[data - '0'] != nullptr){
                root = root -> numbers[data - '0'];
                result++;
            }else{
                break;
            }
        }

        return result;   
    }

public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();

        for(int i = 0; i < arr2.size(); i++){
            string number = to_string(arr2[i]);
            constructTree(root, number);
        }


        int answer = 0;
        for(auto data : arr1){
            string temp = to_string(data);
            int result = traverse(root,temp);
            answer = max(answer, result);
        }

        return answer;
    }
};