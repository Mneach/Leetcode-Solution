class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<pair<int,int>>> adjList(26);

        for(int i = 0; i < original.size(); i++){
            adjList[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }


        vector<vector<long long>> shortestPath(26, vector<long long int>(26));

        for(int i = 0; i < 26; i++){
            
            // do djikstra algorithm for all lower case character

            priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<pair<long long, int>>> pq;

            pq.push({0, i});

            vector<long long> minCost(26, INT_MIN);

            while(pq.empty() == false){
                auto [currentCost, currentChar] = pq.top();
                pq.pop();

                if(minCost[currentChar] != INT_MIN && minCost[currentChar] < currentCost){
                    continue;
                }

                // visit all connected nodes
                for(auto& [targetChar, conversionCost] : adjList[currentChar]){
                    long long newTotalCost = currentCost + conversionCost;

                    if(minCost[targetChar] == INT_MIN || newTotalCost < minCost[targetChar]){
                        minCost[targetChar] = newTotalCost;

                        pq.push({newTotalCost, targetChar});
                    }
                }
            }

            shortestPath[i] = minCost;
        }

        long long answer = 0;
        bool valid = true;
        
        for(int i = 0; i < source.length(); i++){
            if(source[i] == target[i]) continue;

            long long cost = shortestPath[source[i] - 'a'][target[i] - 'a'];

            if(cost == INT_MIN){
                valid = false;
                break;
            }

            answer += cost;
        }

        if(valid == false) return -1;

        return answer;
    }
};