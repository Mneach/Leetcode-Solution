class Solution {
public:
    
    int distance(char find, string keyboard){
        
        int target = 0;
        for(int i = 0; i < keyboard.length(); i++){
            if(keyboard[i] == find){
                target = i;
                break;
            }
        }
        
        return target;
    }
    
    int calculateTime(string keyboard, string word) {
            
        int answer = 0;
        int current = 0;
        for(int i = 0; i < word.length(); i++){
            
            int targetPosition = distance(word[i], keyboard);
            answer += abs(current - targetPosition);
            current = targetPosition;
        }
        
        return answer;
    }
};