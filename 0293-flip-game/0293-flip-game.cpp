class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        
        vector<string> answer;
        
        for(int i = 0; i < currentState.length() - 1; i++){
            
            if(currentState[i] == '+' && currentState[i + 1] == '+'){
                string temp = currentState;
                temp[i] = '-';
                temp[i + 1] = '-';
                
                answer.push_back(temp);
            }
        }
        
        return answer;
    }
};