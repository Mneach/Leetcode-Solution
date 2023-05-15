class Solution {
public:
    string interpret(string command) {
        string answer = "";
        
        for(int i = 0; i < command.length(); i++){
            if(command[i] == '(' && command[i + 1] == ')'){
                answer.push_back('o');
                i++;
            }else if(command[i] == '(' && command[i + 1] == 'a'){
                answer.push_back('a');
                answer.push_back('l');
                i+= 3;
            }else{
                answer.push_back(command[i]);
            }
        }
        
        return answer;
    }
};