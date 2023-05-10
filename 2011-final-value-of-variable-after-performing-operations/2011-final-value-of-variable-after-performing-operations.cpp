class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int total = 0;
        
        for(int i = 0; i < operations.size(); i++){
            string input = operations[i];
            
            if(input == "++X" || input == "X++") total++;
            else total--;
        }
        
        return total;
    }
};