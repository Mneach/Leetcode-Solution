class Solution {
public:

    void dfs(string tiles, int currentIndex, string current, unordered_map<string,int> &ump, vector<bool> visited){
        if(ump[current] > 0){
            return;
        }

        ump[current]++;

        for(int i = 0; i < tiles.length(); i++){
            if(visited[i] == false){
                visited[i] = true;
                dfs(tiles, i + 1, current + tiles[i], ump, visited);
                visited[i] = false;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_map<string,int> ump;
        vector<bool> visited(tiles.size(), false);
        
        dfs(tiles, 0, "", ump, visited);

        return ump.size() - 1;
    }
};