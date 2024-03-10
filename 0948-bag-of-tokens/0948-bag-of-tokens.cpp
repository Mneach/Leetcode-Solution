class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0;
        
        int tempScore = 0;
        int right = tokens.size() - 1;
        
        sort(tokens.begin(), tokens.end());
        for(int i = 0; i < tokens.size(); i++){
            
            if(power < tokens[i] && tempScore > 0){
                power += tokens[right];
                score = max(tempScore, score);
                tempScore--;
                right--;
            }
            
            if(power >= tokens[i]){
                power -= tokens[i];
                tempScore++;
            }
            // cout << power << " " << tempScore << " " << score << endl;
            if(i > right || right < 0) break;
        }
        
        score = max(tempScore, score);
        
        return score;
    }
};