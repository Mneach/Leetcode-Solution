class Solution {
public:
    int calPoints(vector<string>& operations) {
        
        stack<int> stack;
        int answer = 0;
        
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] == "C") {
                stack.pop();
            }
            else if(operations[i] == "D") {
                int temp = stack.top();
                stack.push(temp * 2);
            }else if(operations[i] == "+"){
                int temp1 = stack.top();
                stack.pop();
                int temp2 = stack.top();
                
                stack.push(temp1);
                stack.push(temp1 + temp2);
            }else{
                stack.push(stoi(operations[i]));
            }         
        }
        
        while(stack.empty() == false){
            answer += stack.top();
            stack.pop();
        }
        
        return answer;
    }
};