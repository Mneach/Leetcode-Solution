class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int> answer;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        for(int i = 0; i < arr.size(); i++){
            pq.push(make_pair(abs(arr[i] - x), i));
        }
        
        while(pq.empty() == false && k > 0){
            pair<int,int> data = pq.top();
            answer.push_back(arr[data.second]);
            pq.pop();
            k--;
        }
        
        sort(answer.begin(), answer.end());
        
        return answer; 
    }
};