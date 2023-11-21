class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
       int minimumSize = INT_MAX;
       for(auto data : strs){
           int length = data.length();
           minimumSize = min(minimumSize,length);
       }
        
       
       vector<string> bucket;
        
       for(auto data : strs){
           string temp = data.substr(0, minimumSize);
           bucket.push_back(temp);
       }
        
       string answer = "";
       for(int i = 0; i < minimumSize; i++){
           
           bool check = true;
           for(int j = 0; j < strs.size() - 1; j++){
               if(strs[j][i] != strs[j + 1][i]){
                   check = false;
                   break;
               }
           }
           
           if(check){
               answer += strs[0][i];
           }else{
               break;
           }
       }
        
       return answer;
    }
};