/*
Intuition :
1. if the cyclic in 1 group is more than 2 nodes, that result should consider as
an answer

Example
favorite = [1,2,3,4,5,3]
answer = 4
cyclic result = 3 -> 4 -> 5 -> 3

2. if the cyclic in 1 group is between 2 nodes, the result should be total node
in that group favorite = [1,2,3,4,5,4] answer = 6 cyclic result = 0 -> 1 -> 2 ->
3 -> 4 <-> 5

3. we alwasy can combine the group that have a cyclic in between 2 node, so this
should consider as the result, since we can choose multiple group with this
condition.

4. if there are more than 1 group in favorit answer, we just need to compare
those groups using the rules above

Time Complexity : O(N)
-> where N is length of favorite array
*/

class Solution {
public:
    int bfs(int startNode, int parent, vector<vector<int>>& invertedGraph) {
        int result = 0;
        // {node, length}
        queue<pair<int, int>> q;
        q.push({startNode, 0});

        while (!q.empty()) {
            auto [node, length] = q.front();
            q.pop();

            if (node == parent)
                continue;

            result = max(result, length);
            for (auto neighbor : invertedGraph[node]) {
                q.push({neighbor, length + 1});
            }
        }

        return result;
    }

    int maximumInvitations(vector<int>& favorite) {
        vector<bool> visited(favorite.size());
        vector<pair<int, int>> cycle2;

        int firstAnswer = -1;
        for (int i = 0; i < favorite.size(); i++) {
            if (visited[i] == true)
                continue;

            int first = i;
            int current = i;
            set<int> bucket;

            while (visited[current] == false) {
                visited[current] = true;
                bucket.insert(current);
                current = favorite[current];
            }

            int length = bucket.size();
            while (first != current) {
                length--;
                first = favorite[first];
            }

            firstAnswer = max(length, firstAnswer);

            if (length == 2) {
                // cycle between node is 2, that means we can add more node in
                // here
                cycle2.push_back({current, favorite[current]});
            }
        }

        vector<vector<int>> invertedGraph(favorite.size());
        for (int i = 0; i < favorite.size(); i++) {
            int dest = i;
            int source = favorite[i];

            invertedGraph[source].push_back(dest);
        }

        // for every cycle 2
        int secondAnswer = 0;
        for (auto data : cycle2) {
            int firstNode = data.first;
            int secondNode = data.second;
            secondAnswer += bfs(firstNode, secondNode, invertedGraph) +
                            bfs(secondNode, firstNode, invertedGraph) + 2;
        }

        return max(firstAnswer, secondAnswer);
    }
};
