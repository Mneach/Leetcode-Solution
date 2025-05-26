class Solution {
    using ColorCount = array<int, 26>; // Represents count of each color (a-z)
    
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        // Build graph and calculate in-degree for each node
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(colors.size(), 0);
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }
        
        // Initialize color counts for each node
        vector<ColorCount> nodeColors(colors.size(), ColorCount{});
        queue<int> processingQueue;
        
        // Initialize queue with source nodes (in-degree = 0)
        for (int node = 0; node < colors.size(); ++node) {
            if (inDegree[node] == 0) {
                processingQueue.push(node);
                nodeColors[node][colors[node] - 'a'] = 1;
            }
        }
        
        int maxColorValue = 0;
        int processedNodes = 0;
        
        while (!processingQueue.empty()) {
            int currentNode = processingQueue.front();
            processingQueue.pop();
            
            // Update the maximum color value found so far
            int currentMax = *max_element(nodeColors[currentNode].begin(), nodeColors[currentNode].end());
            maxColorValue = max(maxColorValue, currentMax);
            
            processedNodes++;
            
            // Process all neighbors
            for (int neighbor : graph[currentNode]) {
                // Update color counts for the neighbor
                for (int color = 0; color < 26; ++color) {
                    int newCount = nodeColors[currentNode][color] + (color == (colors[neighbor] - 'a'));
                    if (newCount > nodeColors[neighbor][color]) {
                        nodeColors[neighbor][color] = newCount;
                    }
                }
                
                // Decrement in-degree and add to queue if it becomes a source node
                if (--inDegree[neighbor] == 0) {
                    processingQueue.push(neighbor);
                }
            }
        }
        
        // Check if we processed all nodes (no cycles)
        return processedNodes == colors.size() ? maxColorValue : -1;
    }
};