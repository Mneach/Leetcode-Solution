class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        priority_queue<pair<int,int>> large;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> small;
        
        int answer = 0;

        for(int i = 0; i < arrays.size(); i++){
            int first = arrays[i][0];
            int end = arrays[i][arrays[i].size() - 1];

            small.push({first, i});
            large.push({end, i});
        }

        if(large.top().second == small.top().second){
            int firstL = large.top().first;
            int firstS = small.top().first;

            large.pop();
            small.pop();

            int secondL = large.top().first;
            int secondS = small.top().first;

            answer = max(firstL - secondS, secondL - firstS);
        }else{
            answer = large.top().first - small.top().first;
        }

        return answer;
    }
};