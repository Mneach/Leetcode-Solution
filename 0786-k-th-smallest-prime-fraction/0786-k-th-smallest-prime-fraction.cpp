class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = i + 1; j < arr.size(); j++){
                double fraction = (double) arr[i] / (double) arr[j];
                pq.push(make_pair(fraction, make_pair(arr[i], arr[j])));
            }
        }
        
        while(k > 1){
            pq.pop();
            k--;
        }
        
        return {pq.top().second.first, pq.top().second.second};
    }
};