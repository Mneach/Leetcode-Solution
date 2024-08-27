class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<double> answer(n);
        answer[start_node] = 1.0;

        for(int i = 0; i < n - 1; i++){
            bool update = false;

            for(int j = 0; j < edges.size(); j++){

                int source = edges[j][0];
                int dest = edges[j][1];
                
                double prob = succProb[j];

                if(answer[source] * prob > answer[dest]){
                    answer[dest] = answer[source] * prob;
                    update = true;
                }

                if(answer[dest] * prob > answer[source]){
                    answer[source] = answer[dest] * prob;
                    update = true;
                }
            }

            if(!update){
                break;
            }
        }

        return answer[end_node];
    }
};