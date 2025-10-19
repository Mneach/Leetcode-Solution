class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {

        int answer = 0;
        for(int i = 0 ; i < sentences.size(); i++){
            
            int countSpace = 1;
            for(int j = 0; j < sentences[i].size(); j++){
                if(sentences[i][j] == ' ') countSpace++;
            }
            
            answer = max(answer , countSpace);
        }
        
        return answer;
    }
};