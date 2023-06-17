class Solution {
public:
    
    int compress(vector<char>& chars) {
        
        vector<char> answer;
        
        int currentChar = chars[0];
        int currentTotal = 1;
        
        for(int i = 1; i < chars.size(); i++){
            if(currentChar != chars[i]){
                answer.push_back(currentChar);
                
                if(currentTotal > 1){
                    string s = to_string(currentTotal);
                    
                    for(int j = 0; j < s.length(); j++){
                        answer.push_back(s[j]);
                    }
                }
                
                currentChar = chars[i];
                currentTotal = 1;
            }else{
                currentTotal++;
            }
        }
        
        answer.push_back(currentChar);
        if(currentTotal > 1){
            string s = to_string(currentTotal);

            for(int j = 0; j < s.length(); j++){
                answer.push_back(s[j]);
            }
        }        
        
        for(int i = 0; i < answer.size(); i++){
            chars[i] = answer[i];
        }
        
        return chars.size() - (chars.size() - answer.size());
    }
};