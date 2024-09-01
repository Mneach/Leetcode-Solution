class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

        vector<vector<int>> answer;
        
        if(m * n != original.size()){
            return answer;
        }

        

        int row = 0;
        int col = 0;
        int current = 1;
        vector<int> temp;
        for(int i = 0; i < original.size(); i++){
            int number = original[i];

            if(current < n){
                temp.push_back(number);
                current++;
            }else if(current == n){
                temp.push_back(number);
                answer.push_back(temp);
                current = 1;
                temp = {};
            }
        }

        return answer;
    }
};