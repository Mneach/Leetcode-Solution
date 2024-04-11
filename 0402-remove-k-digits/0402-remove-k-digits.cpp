class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        
        for(int i = 0; i < num.size(); i++){
            while(st.empty() == false && k > 0 && st.top() > num[i]){
                st.pop();
                k -= 1;
            }
            
            st.push(num[i]);
        }
        
        for(int i = 0; i < k; i++){
            st.pop();
        }
        
        string bucket = "";
        
        while(st.empty() == false){
            bucket += st.top();
            st.pop();
        }
        
        reverse(bucket.begin(), bucket.end());
        
        string answer = "";
        bool checkZero = true;
        for(int i = 0; i < bucket.size(); i++){
            
            if(checkZero && bucket[i] == '0') continue;
            checkZero = false;
            
            answer += bucket[i];
        }
                
        
        if(answer.length() == 0) return "0";
        
        return answer;
    }
};