class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string> stack;
        
        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../" && stack.empty() == false) stack.pop();
            else if(logs[i] != "./" && logs[i] != "../") stack.push(logs[i]);
            
        }
        
        return stack.size();
    }
};