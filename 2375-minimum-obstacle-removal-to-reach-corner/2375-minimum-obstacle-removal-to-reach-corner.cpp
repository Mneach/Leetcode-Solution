
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
    bool operator()(Node first, Node second){
        return first.cost > second.cost;
    }
};

class Solution {
public:

    int moveX[4] = {-1, 0, 1, 0};
    int moveY[4] = {0, -1, 0, 1};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        priority_queue<Node, vector<Node>, Compare> pq; 

        pq.push(Node(0,0,0));

        while(pq.size() > 0) {
            auto [x,y,cost] = pq.top();
            pq.pop();

            if(x == grid.size() -1  && y == grid[0].size() - 1) {
                return cost;
            }

            for(int i = 0; i < 4; i++){
                int nextX = x + moveX[i];
                int nextY = y + moveY[i];

                if(nextX < 0 || nextX >= grid.size()) continue;
                else if(nextY < 0 || nextY >= grid[0].size()) continue;
                else if(visited[nextX][nextY]) continue;

                int newCost = cost + grid[nextX][nextY];

                pq.push(Node(nextX, nextY, newCost));
                visited[nextX][nextY] = true;
            } 
        }

        // for(auto row : visited) {
        //     for(auto col : row) {
        //         cout << col << " ";
        //     }
        //     cout << endl;
        // }

        return -1;
    }
};