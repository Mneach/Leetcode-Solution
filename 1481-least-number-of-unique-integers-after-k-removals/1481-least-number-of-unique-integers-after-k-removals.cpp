class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        map<int,int> mp;
        
        int maxNumber = 0;
        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }
        
        priority_queue <int, vector<int>, greater<int>> pq;
        
        for(auto data : mp){
            pq.push(data.second);
        }
        
        int curr = 0;
        
        while(curr < k){
            int top = pq.top();
            
            int diff = k - (top + curr);
            if(diff < 0){
                break;
            }else{
                pq.pop();
                curr += top;
            }
        }
        
        return pq.size();
    }
};