class Solution {

private:

    struct CompareMin{
        bool operator()(const pair<int,int> p1, const pair<int,int> p2){
            return p1.second > p2.second;
        }
    };

    pair<int,int> djikstra(int start, vector<vector<pair<int,int>>> &adjList, int maxDist){

        priority_queue<pair<int,int>, vector<pair<int,int>>, CompareMin> pq;
        vector<bool> visited(adjList.size(), false);

        pq.push({start, 0});
        int total = 0;

        while(pq.empty() == false){
            auto [currentNode, currentCost] = pq.top();
            pq.pop();

            if(visited[currentNode] == true) continue;
            total++;
            visited[currentNode] = true;
            
            for(auto node : adjList[currentNode]){
                if(visited[node.first] == false && currentCost + node.second <= maxDist){
                    pq.push({node.first, currentCost + node.second});
                }
            }
        }

        return make_pair(start, total);
    }

    struct Comparator{
        bool operator()(const pair<int,int> p1, const pair<int,int> p2){
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }else{
                return p1.second > p2.second;
            }
        }
    };

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adjList(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, Comparator> pq;

        for(int i = 0; i < edges.size(); i++){
            int source = edges[i][0];
            int dest = edges[i][1];
            int cost = edges[i][2];

            adjList[source].push_back({dest, cost});
            adjList[dest].push_back({source, cost});
        }

        // for(int i = 0; i < adjList.size(); i++){
        //     cout << "source : " << i << " ";
        //     for(auto data : adjList[i]){
        //         cout << data.first << " ";
        //     }

        //     cout << endl;
        // }        

        for(int i = 0; i < adjList.size(); i++){
            auto result = djikstra(i, adjList, distanceThreshold);
            cout << result.first << " " << result.second << endl;
            pq.push(result);
        }

        return pq.top().first;
    }
};


/*

Logic : 
1. we need to convert the edges array to adj list, so we can easyly
2. to get the maximum nodes that can visit from the current nodes, we can use djikstra algorithm to check the nodes that can current nodes visit
3. we can save the result inside priority queue of pair<int,int> where pair first for nodes number and the pair second for total node that can we visit
4. sort the data on priority queue based on the problem statement
5. we can use pq.top() to get the result

Time complexity O(N^2)
Space Complexity O(N^2)

*/