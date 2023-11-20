class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        priority_queue<pair<int,int>> pq;
        map<int,int> mp;
        
        int answer = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }
        
        for(auto data : mp){
            pq.push(make_pair(data.first, data.second));
        }
        
        
        int current = pq.top().second;
        while(pq.size() > 1){
            pair<int,int> right = pq.top();
            pq.pop();
            pair<int,int> left = pq.top();
            
            if(right.first != left.first){
                answer += current;
                current += left.second;
            }
        }
        
        return answer;
    }
};