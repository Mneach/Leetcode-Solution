class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char,int> arr;
        
        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;
        
        int answer = 0;
        bool check = false;
        for(int i = 0; i < s.length() - 1; i++){
           if(arr[s[i]] >= arr[s[i + 1]]){
               answer += arr[s[i]]; 
           }else{
               if(i == s.length() - 2) check = true;
               answer += arr[s[i + 1]] - arr[s[i]];
               i++;
           }
        }
        
        if(!check) answer += arr[s[s.length() - 1]];
        
        return answer;
    }
};