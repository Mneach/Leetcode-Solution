class Solution {
public:
    
    priority_queue<int, vector<int>, greater<int>> pq;
    stack<pair<char,int>> st;
    
    string minRemoveToMakeValid(string s) {
        
        for(int i = 0; i < s.length(); i++){
            
            if(st.empty() && s[i] == '('){
                st.push(make_pair(s[i], i));
            }else if(st.empty() && s[i] == ')'){
                pq.push(i);
            }else if(s[i] == ')'){
                st.pop();
            }else if(s[i] == '('){
                st.push(make_pair(s[i], i));
            }
        }
        
        while(st.empty() == false){
            pq.push(st.top().second);
            st.pop();
        }
        
        string answer = "";
        for(int i = 0; i < s.length(); i++){
            if(pq.empty() == false && pq.top() == i){
                pq.pop();
            }else{
                answer += s[i];
            }
        }
        
        return answer;
    }
};