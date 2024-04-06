class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int> mp;
        priority_queue<int> pq;
        
        for(auto data : arr){
            mp[data]++;
        }
        
        for(auto data : mp){
            pq.push(data.second);
        }
        
        int minimum = arr.size() / 2;
        
        int count = 0;
        int answer = 0;
        while(pq.empty() == false && count < minimum){
            answer++;
            count += pq.top();
            pq.pop();
        }
        
        return answer;
    }
};