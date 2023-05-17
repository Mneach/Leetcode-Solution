class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> answer(boxes.size());
        
        for(int i = 0; i < boxes.size(); i++){
            
            int totalLeft = 0;
            int totalRight = 0;
            
            for(int j = 0; j < i; j++){
                if(boxes[j] == '1') totalLeft += i - j;
            }
            
            for(int k = i; k < boxes.size(); k++){
                if(boxes[k] == '1') totalRight += k - i;
            }
            
            answer[i] = totalLeft + totalRight;
        }
        
        return answer;
    }
};