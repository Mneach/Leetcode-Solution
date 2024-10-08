class Solution {
public:
    int minSwaps(string s) {
        
        stack<char> st;

        for(auto data : s){
            if(st.empty()){
                st.push(data);
            }else if(st.top() == '[' && data == ']'){
                st.pop();
            }else{
                st.push(data);
            }
        }

        int pair = st.size() / 2;

        if(pair % 2 == 0){
            return pair / 2;
        }else{
            return (pair / 2) + 1;
        }

    }
};