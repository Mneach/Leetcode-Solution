class Solution {
public:
    
    char findMinWord(vector<int> freq){
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return 'a' + i;
        }
        
        return 'a';
    }
    
    string robotWithString(string s) {
        
        vector<int> freq(26, 0);
        
        for(int i = 0; i < s.length(); i++){
            freq[s[i] - 'a']++;
        }
        
        stack<char> st;
        string answer = "";
        
        for(auto data : s){
            st.push(data);
            freq[data - 'a']--;
            
            while(st.empty() == false && st.top() <= findMinWord(freq)){
                answer += st.top();
                st.pop();
            }
        }
        
        while(st.empty() == false){
            answer += st.top();
            st.pop();
        }
        
        return answer;
    }
};