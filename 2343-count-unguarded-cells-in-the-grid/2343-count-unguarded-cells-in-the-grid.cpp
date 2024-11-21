class Solution {
public:

    int VISITED = 1;
    int GUARD = 2;
    int WALL = 3;


    void floodFill(vector<vector<int>> &map, int row, int col, int move){
        if(row < 0 || col < 0) return;
        else if(row == map.size() || col == map[0].size()) return;

        if(map[row][col] == WALL || map[row][col] == GUARD) return;

        map[row][col] = VISITED;

        if(move == 1) floodFill(map, row - 1,  col, move);
        else if(move == 2) floodFill(map, row + 1, col, move);
        else if(move == 3) floodFill(map, row, col - 1, move);
        else if(move == 4) floodFill(map, row, col + 1, move);
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> map(m, vector<int>(n, 0));

        for(auto data : guards){
            int row = data[0];
            int col = data[1];

            map[row][col] = GUARD;
        }

        for(auto data : walls){
            int row = data[0];
            int col = data[1];
            
            map[row][col] = WALL;
        }

        for(auto data : guards){
            int row = data[0];
            int col = data[1];

            floodFill(map, row - 1, col, 1); // move top 
            floodFill(map, row + 1, col, 2); // move bottom 
            floodFill(map, row, col - 1, 3); // move left
            floodFill(map, row, col + 1, 4); // move right
            
        }

        int answer = 0;
        for(int row = 0; row < map.size(); row++){
            for(int col = 0; col < map[0].size(); col++){
                if(map[row][col] == 0) answer++;
            }
        }

        return answer;
    }
};

/*

0 -> valid
1 -> not valid

wall and guard will mark as not valid

Idea : 
1. create 2d array that can represent the map
2. initialize that 2d array with 0
3. mark guard position, and mark guards as not valid answer
4. mark walls position
5. currentAnswer = m * n -> assume there is no guard and wall 
6. loop for every guard position
   - curerntAnswer -= 1 
   - running floodfill algorithm
   - for every cell, mark as visited / not valid so we cant visit that cell anymore in the next time
7. for every cell that mark as visited / not valid, guard, and walls, we need to decrement currentAnswer - 1

floodFill algoritm
- just visit cell with 4 direction
- make sure we are not visit position outisde the map
- maeks ure we are not visit cell that not valid
  - we define invalid cell, if the cell is already visited, guard, or wall.

Time compleixty
(N * M) -> because we must visit all the cell to know the answer

Memory Compleixty
(N * M) -> because we need to create a map in the beggining of the program 
*/
