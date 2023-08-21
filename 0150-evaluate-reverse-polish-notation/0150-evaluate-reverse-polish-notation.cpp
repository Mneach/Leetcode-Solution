class Solution {
public:
    
    int generateNumber(string x){
        int end = 0;
        if(x[0] == '-') end = 1;
        
        int multipCurrent = 0;
        int answer = 0;
        
        for(int i = x.length() - 1; i >= end; i--){
            int current = x[i] - '0';
            answer += (current * pow(10, multipCurrent));
            multipCurrent++;
        }
        
        if(end == 1) answer *= -1;
        
        return answer;
    }
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        
        string operators = "+-/*";
        
        for(int i = 0; i < tokens.size(); i++){
            
            if(operators.find(tokens[i][0]) != string::npos && tokens[i].size() == 1){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                
                int result;
                
                if(tokens[i][0] == '+') result = second + first;
                else if(tokens[i][0] == '-') result = second - first;
                else if(tokens[i][0] == '*') result = second * first;
                else if(tokens[i][0] == '/') result = second / first;
                
                //cout << " " << first << " " << second << " " << result << endl;
                st.push(result);
            }else{
                int number = generateNumber(tokens[i]);
                st.push(number);
            }
        }
        
        return st.top();
    }
};