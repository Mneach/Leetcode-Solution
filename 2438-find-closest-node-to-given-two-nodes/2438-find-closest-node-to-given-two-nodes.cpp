class GraphTraversal {
public:
    static void performBFS(int startNode, const vector<int>& edges, vector<int>& distances) {
        int n = edges.size();
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(startNode);
        distances[startNode] = 0;
        visited[startNode] = true;

        while (!q.empty()) {
            int currentNode = q.front();
            q.pop();

            int neighbor = edges[currentNode];
            if (neighbor != -1 && !visited[neighbor]) {
                distances[neighbor] = distances[currentNode] + 1;
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
};

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int n = edges.size();
        const int INF = numeric_limits<int>::max();
        
        vector<int> distancesFromNode1(n, INF);
        vector<int> distancesFromNode2(n, INF);
        
        GraphTraversal::performBFS(node1, edges, distancesFromNode1);
        GraphTraversal::performBFS(node2, edges, distancesFromNode2);
        
        return findOptimalMeetingNode(distancesFromNode1, distancesFromNode2);
    }

private:
    int findOptimalMeetingNode(const vector<int>& dist1, const vector<int>& dist2) {
        int minMaxDistance = numeric_limits<int>::max();
        int resultNode = -1;
        
        for (int node = 0; node < dist1.size(); ++node) {
            if (dist1[node] == numeric_limits<int>::max() || dist2[node] == numeric_limits<int>::max()) {
                continue;
            }
            
            int currentMax = max(dist1[node], dist2[node]);
            if (currentMax < minMaxDistance || 
                (currentMax == minMaxDistance && node < resultNode)) {
                minMaxDistance = currentMax;
                resultNode = node;
            }
        }
        
        return resultNode;
    }
};