class Node {
public:
    int row;
    int col;
    int height;

    Node(int row, int col, int height) {
        this -> row = row;
        this -> col = col;
        this -> height = height;
    }
};

struct Compare {
    bool operator()(Node& first, Node& second){
        return first.height > second.height;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int totalRow = heightMap.size();
        int totalCol = heightMap[0].size();
        int moveRow[4] = {0,-1,0,1};
        int moveCol[4] = {-1,0,1,0};
        priority_queue<Node, vector<Node>, Compare> pq;
        
        for (int row = 0; row < totalRow; row++) {
            for (int col = 0; col < totalCol; col++) {
                int height = heightMap[row][col];
                if (row == 0 || row == totalRow - 1) {
                    pq.push(Node(row, col, height));
                    heightMap[row][col] = -1;
                } else if (col == 0 || col == totalCol - 1) {
                    pq.push(Node(row,col,height));
                    heightMap[row][col] = -1;
                }
            }
        }


        int answer = 0;
        int maxHeight = 0;
        while (!pq.empty()) {
            auto [row, col, height] = pq.top();
            maxHeight = max(maxHeight, height);
            answer += maxHeight - height;
            pq.pop();

            for (int move = 0; move < 4; move++) {
                int nextRow = row + moveRow[move];
                int nextCol = col + moveCol[move];

                if (nextRow < 0 || nextRow >= totalRow) continue;
                else if (nextCol < 0 || nextCol >= totalCol) continue;
                else if (heightMap[nextRow][nextCol] == -1) continue;

                pq.push(Node(nextRow, nextCol, heightMap[nextRow][nextCol]));

                heightMap[nextRow][nextCol] = -1;
            }
        }

        return answer;
    }
};


