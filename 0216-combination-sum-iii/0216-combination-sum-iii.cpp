class Solution {
public:
    
    void recursive(vector<vector<int>> &answers, int k, int n, int current, vector<int> temp){
        
        if(k == 1){
            if(n == current){
                temp.push_back(current);
                answers.push_back(temp);
            }
        }else if(current > n){
            return;
        }else{
            k--;
            n -= current;
            temp.push_back(current);
            for(int i = current + 1; i <= 9; i++){
                recursive(answers, k, n, i , temp);
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answers;
        vector<int> temp;
        
        
        for(int i = 1; i <= 9; i++){
            recursive(answers, k, n , i, temp);
        }
        
        return answers;
    }
};