class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }
        
        vector<int> answer;
        
        while(!pq.empty()){
            answer.push_back(pq.top());
            pq.pop();
        }
        
        return answer;
    }
};