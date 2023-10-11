class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < mat.size(); i++){
            
            int totalSoldier = 0;
            for(int j = 0; j < mat[i].size(); j++){
                if(mat[i][j] == 0) break;
                else totalSoldier++;
            }
            
            pq.push(make_pair(totalSoldier, i));
        }
        
        
        vector<int> answer;
        
        while(!pq.empty()){
            k--;
            answer.push_back(pq.top().second);
            pq.pop();
            if(k == 0) break;
        }
        
        return answer;
    }
};