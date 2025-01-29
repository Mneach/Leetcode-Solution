
/*

Intuition : 
1. cyclic alwasy happen in this graph, since edges == nodes
2. need to track the parent for backtracking after we find a cyclic
3. we can use disjoint set to solve the problem 

*/

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int totalNode = edges.size();
        vector<vector<int>> adjList(totalNode + 1);

        for (auto edge : edges) {
            int source = edge[0];
            int dest = edge[1];

            adjList[source].push_back(dest);
            adjList[dest].push_back(source);
        }

        vector<int> parent(totalNode + 1, -1);
        vector<bool> visited(totalNode + 1, false);

        int find = -1;
        int prevFindNode = -1;
        for (int i = 1; i <= totalNode; i++) {
            if (visited[i] == true) continue;

            queue<int> q;
            q.push(i);

            while(!q.empty()) {
                int node = q.front();
                visited[node] = true;
                q.pop();

                for (auto nextNode : adjList[node]) {
                    if (nextNode == parent[node]) continue;
                    if (visited[nextNode] == true) {
                        prevFindNode = node;
                        find = nextNode;
                        break;
                    }
                    parent[nextNode] = node;
                    q.push(nextNode);
                }

                if (find != -1) break;
            }

            if (find != -1) break;
        }

        // reset visited array
        fill(visited.begin(), visited.end(), false);

        // start from find node to parent
        // find the same parent between find node and prevFindNode

        vector<vector<int>> tempPath;
        tempPath.push_back({prevFindNode, find});

        while(parent[find] != -1) {
            tempPath.push_back({parent[find], find});
            visited[find] = true;
            find = parent[find];
        }

        vector<vector<int>> path;
        path.push_back(tempPath[0]);
        while (parent[prevFindNode] != -1 && visited[prevFindNode] == false) {
            path.push_back({parent[prevFindNode], prevFindNode});
            visited[prevFindNode] = true;
            prevFindNode = parent[prevFindNode];
        }

        for (int i = 0; i < tempPath.size(); i++) {
            path.push_back(tempPath[i]);
            if (tempPath[i][0] == prevFindNode || tempPath[i][1] == prevFindNode) {
                break;
            }
        }

        int answerIndex = -1;
        for (auto data : path) {
            int source = data[0];
            int dest = data[1];

            if (source == -1 || dest == -1) {
                continue;
            }

            for (int i = 0; i < edges.size(); i++) {

                if (
                    (edges[i][0] == source && edges[i][1] == dest) || 
                    (edges[i][1] == source && edges[i][0] == dest)
                ) {
                    answerIndex = max(i, answerIndex);
                    break;
                }
            }
        }
        
        
        return edges[answerIndex];
    }
};