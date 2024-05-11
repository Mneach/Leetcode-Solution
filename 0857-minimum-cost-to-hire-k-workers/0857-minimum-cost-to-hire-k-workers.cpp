class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int size = wage.size();
        
        vector<pair<double,int>> arr;
        
        for(int i = 0; i < size; i++){
            double unit = (double) wage[i] / (double) quality[i];
            arr.push_back(make_pair(unit, quality[i]));
        }
        
        sort(arr.begin(), arr.end());
        
        priority_queue<int> highestQuality;
        double totalQuality = 0;
        double answer = DBL_MAX;
        
        for(int i = 0; i < size; i++){
            highestQuality.push(arr[i].second);
            totalQuality += arr[i].second;
            
            if(highestQuality.size() == k){
                answer = min(answer, totalQuality * arr[i].first);
            }else if(highestQuality.size() > k){
                totalQuality -= highestQuality.top();
                highestQuality.pop();
                answer = min(answer, totalQuality * arr[i].first);
            }
            
        }
        
        return answer;
    }
};