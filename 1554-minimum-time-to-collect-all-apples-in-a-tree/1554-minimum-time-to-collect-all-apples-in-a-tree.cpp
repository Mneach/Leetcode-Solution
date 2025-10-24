
/*

# Observation
1.	Given an undirected tree consisting of n vertices numbered from 0 to n-1
2.	You spend 1 second to walk over one edge of the tree.
3.	We need to collect all of the apples in the tree, we also need to getback to vertex 0 (root)
4.	we are given edges[i] = {source, dest}
5.	we are give hasApple[i] = (true / false), represent the vertex i has apple or not
6.	Our task is to return minimum in seconds you have to spend to collect all apples in the tree, starting at vertex 0 and coming back to this vertex

# DFS 

# Simulation


       0
      / \
     1   2
    /\   /\
   4  5  3 6

has apple = [false,false,true,false,false,true,false]
has apple = [node(2), node(5)]

run post order traversal

process 1 : 
node(4) -> node(1)
        -> node(2)

process 2 : 

node(1) -> node(4) 
        -> node(5)

process 3 : 
node(4) -> NULL -> return 0
        -> NULL -> return 0

node(4) -> return 0

process 4 :

node(5) -> NULL -> return 0
        -> NULL -> return 0

node(5) -> return 2

proess 5 :
node(1) -> node(4) -> 0
        -> node(5) -> 2

node(1) -> 2 + node(4) + node(5) = 4

process 6 : 
node(2) -> node(3) -> return 0
        -> node(6) -> return 0

node(2) -> 2 + node(3) + node(6) = 2

result = 6

# Pseudocode
1.	initialize variables
   - vector<vector<int>> adjList
2. convert the edges to adj list
3. create dfs functions (node, parent)
   - int total = 0
   - for every data in adj list
     - if the next node == parent, just continue
     - visit the next node and get the result from next node
     - if the result != 0, then add total by result
   - if total != 0
     - total += 2, because of we need to visit current node and get back to the parent
   - if hasApple[node] == true
     - total += 2
   - return total
4. call dfs function
   - result = dfs(0)
5. return the result

Time Complexity : O(N + E)
N -> total nodes in the tree
E -> total edges

Memory Complexity : O(H)
H -> height of the tree


*/

class Solution {
private:
    int dfs(vector<vector<int>> &adjList, vector<bool> &hasApple, int node, int parent) {
        int total = 0;
        for (auto nextNode : adjList[node]) {
            if (nextNode == parent) {
                continue;
            }

            total += dfs(adjList, hasApple, nextNode, node);
        }

        if ((total != 0 || hasApple[node] == true) && node != 0) {
            total += 2;
        }

        return total;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjList(n);

        // convert edges to adj list
        for (auto edge : edges) {
            int source = edge[0];
            int dest = edge[1];

            adjList[source].push_back(dest);
            adjList[dest].push_back(source); 
        }

        int result = dfs(adjList, hasApple, 0, -1);

        return result;
    }
};