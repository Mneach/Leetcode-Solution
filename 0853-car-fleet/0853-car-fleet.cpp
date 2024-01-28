class Solution {
public:
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,int>> bucket;
        int answer = 0;
        
        for(int i = 0; i < position.size(); i++){
            bucket.push_back(make_pair(position[i], speed[i]));
        }
        
        sort(bucket.begin(), bucket.end(), greater<pair<int,int>>());
        
        stack<float> st;
        for(int i = 0; i < position.size(); i++){
            int currentPosition = bucket[i].first;
            float currentSpeed = bucket[i].second;
            float distance = (target - currentPosition) / currentSpeed;
            
            if(st.empty()){
                st.push(distance);
                answer++;
            }else{
                float prevDistance = st.top();
                // cout << distance << " " << prevDistance << endl;
                if(distance > prevDistance){
                    answer++;
                    st.push(distance);
                }
            }
        }
        
        return answer;
    }
};