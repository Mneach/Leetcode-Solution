class Solution {
public:
    int minimumPushes(string word) {
        int answer = 0; 
        
        int increment = 0;
        for(int i = 0; i < word.length(); i++){
            if(i % 8 == 0){
                increment++;
            }
            
            answer += increment;
        }
        
        return answer;
    }
};