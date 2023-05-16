class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        
        int answer = 0;
        
        for(int i = 0; i < items.size(); i++){
            
            int checkIndex = -1;
            if(ruleKey == "type") checkIndex = 0;
            else if(ruleKey == "color") checkIndex = 1;
            else checkIndex = 2;
            
            if(items[i][checkIndex] == ruleValue) answer++;
        }
        
        return answer;
    }
};