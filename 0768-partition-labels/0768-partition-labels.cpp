class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<char,int> ump;
        vector<int> answer;
        
        for(int i = 0; i < s.length(); i++){
            ump[s[i]] = i;
        }
        
        int left = 0;
        int right = ump[s[0]];
        
        for(int i = 0; i < s.length(); i++){
            if(i < right && ump[s[i]] > right){
                right = ump[s[i]];
            }else if(i > right && ump[s[i]] > right){
                answer.push_back(right - left + 1);
                left = i;
                right = ump[s[i]];
            }
        }
        
        answer.push_back(right - left + 1);
        
        return answer;
    }
};