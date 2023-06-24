class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        
        int answer = 0;
        
        for(int i = 0; i < words.size(); i++){
            string temp = words[i];
            for(int j = i + 1; j < words.size(); j++){
                string compare = words[j];
                
                reverse(compare.begin(), compare.end());
                
                if(temp == compare) answer++;
            }
        }
        
        return answer;
    }
};