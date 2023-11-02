class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int> arr;
        
        for(int i = 0; i < s.length(); i++){
            arr[s[i]]++;
        }
        
        int answer = 0;
        
        bool checkOne = false;
        for(auto data : arr){
            if(data.second % 2 == 0){
                answer += data.second;
            }else if(data.second > 1){
                answer += (data.second - 1);
                if(!checkOne){
                    answer += 1;
                    checkOne = true;
                }
            }else if(data.second == 1 && !checkOne){
                answer += 1;
                checkOne = true;
            }
        }
        
        return answer;
    }
};