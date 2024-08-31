#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Solution {
public:
    const int INF = 2e9;

    std::vector<std::vector<int>> modifiedGraphEdges(int nodeCount,
                                                     std::vector<std::vector<int>>& edges,
                                                     int source, int destination,
                                                     int target) {
        long long currentShortestDistance = runDijkstra(edges, nodeCount, source, destination);

        if (currentShortestDistance < target) return {};

        bool matchesTarget = (currentShortestDistance == target);

        for (auto& edge : edges) {
            if (edge[2] > 0) continue;

            edge[2] = matchesTarget ? INF : 1;

            if (!matchesTarget) {
                long long newDistance = runDijkstra(edges, nodeCount, source, destination);
                if (newDistance <= target) {
                    matchesTarget = true;
                    edge[2] += target - newDistance;
                }
            }
        }

        return matchesTarget ? edges : std::vector<std::vector<int>>{};
    }

private:
    long long runDijkstra(const std::vector<std::vector<int>>& edges, int nodeCount,
                          int source, int destination) {
        std::vector<std::vector<long long>> adjMatrix(nodeCount, std::vector<long long>(nodeCount, INF));
        std::vector<long long> minDistance(nodeCount, INF);
        std::vector<bool> visited(nodeCount, false);

        minDistance[source] = 0;

        buildAdjMatrix(edges, adjMatrix);

        for (int i = 0; i < nodeCount; ++i) {
            int u = findNearestUnvisitedNode(minDistance, visited, nodeCount);
            if (u == -1) break; // All reachable nodes are visited

            visited[u] = true;

            for (int v = 0; v < nodeCount; ++v) {
                if (!visited[v] && adjMatrix[u][v] < INF) {
                    minDistance[v] = std::min(minDistance[v], minDistance[u] + adjMatrix[u][v]);
                }
            }
        }

        return minDistance[destination];
    }

    void buildAdjMatrix(const std::vector<std::vector<int>>& edges,
                        std::vector<std::vector<long long>>& adjMatrix) {
        for (const auto& edge : edges) {
            if (edge[2] != -1) {
                adjMatrix[edge[0]][edge[1]] = edge[2];
                adjMatrix[edge[1]][edge[0]] = edge[2];
            }
        }
    }

    int findNearestUnvisitedNode(const std::vector<long long>& minDistance,
                                 const std::vector<bool>& visited, int nodeCount) {
        int nearestNode = -1;
        for (int i = 0; i < nodeCount; ++i) {
            if (!visited[i] && (nearestNode == -1 || minDistance[i] < minDistance[nearestNode])) {
                nearestNode = i;
            }
        }
        return nearestNode;
    }
};
