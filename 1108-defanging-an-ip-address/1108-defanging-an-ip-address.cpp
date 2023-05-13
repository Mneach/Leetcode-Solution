class Solution {
public:
    string defangIPaddr(string address) {
        
        string answer;
        for(int i = 0; i < address.length(); i++){
            if(address[i] == '.'){
                answer.push_back('[');
                answer.push_back('.');
                answer.push_back(']');
            }else{
                answer.push_back(address[i]);
            }
        }
        
        return answer;
    }
};