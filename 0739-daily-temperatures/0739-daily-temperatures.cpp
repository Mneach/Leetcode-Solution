class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int> arr(temperatures.size(), 0);
        stack<pair<int,int>> st;
        
        for(int i = 0; i < temperatures.size(); i++){
            
            int current = temperatures[i];
            
            if(st.empty()){
                st.push(make_pair(current,i));
            }else{
                while(!st.empty() && st.top().first < current){
                    arr[st.top().second] = i - st.top().second;
                    st.pop();
                }
                
                st.push(make_pair(current, i));
            }
        }
        
        return arr;    
    }
};