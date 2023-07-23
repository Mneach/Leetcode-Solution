class Solution {
public:
    string sortVowels(string s) {
       vector<char> vowels;
       vector<int> position;
       
       string check = "aiueoAIUEO"; 
        
       for(int i = 0; i < s.length(); i++){
           if(check.find(s[i]) != string::npos){
              position.push_back(i);
              vowels.push_back(s[i]);   
           }
       }   
       
       sort(vowels.begin(), vowels.end());
       for(int i = 0; i < position.size(); i++){
           s[position[i]] = vowels[i];
       }  
       
       return s; 
    }
};