class Node {

public:
    int x;
    int y;
    int cost;

    Node(int x, int y, int cost) {
        this -> x = x;
        this -> y = y;
        this -> cost = cost;
    }
};

class Compare {
public:
    bool operator()(Node first, Node second) {
        return first.cost > second.cost;
    }
};

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int moveX[4] = {-1, 0, 1, 0};
        int moveY[4] = {0, -1, 0, 1};

        if(grid[1][0] > 1 && grid[0][1] > 1) return -1;

        priority_queue<Node, vector<Node>, Compare> pq;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        pq.push(Node(0,0,0));
        visited[0][0] = true;

        while(pq.size() > 0) {
            auto [x, y , cost] = pq.top();
            pq.pop();

            if(x == grid.size() - 1 && y == grid[0].size() - 1) {
                return cost;
            }

            for(int i = 0; i < 4; i++) {
                int nextRow = x + moveX[i];
                int nextCol = y + moveY[i];

                if(nextRow < 0 || nextCol < 0 || nextRow >= grid.size() || nextCol >= grid[0].size()) {
                    continue;
                } else if (visited[nextRow][nextCol]) {
                    continue;
                }

                visited[nextRow][nextCol] = true;

                int waitCost = (grid[nextRow][nextCol] - cost) % 2 == 0 ? 1 : 0;
                int nextCost = max(grid[nextRow][nextCol] + waitCost, cost + 1);
                pq.push(Node(nextRow, nextCol, nextCost));
            }
        }

        return -1;
    }
};